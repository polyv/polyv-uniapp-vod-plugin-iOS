

该插件封装了保利威 Android 与 iOS 原生点播 SDK，集成了保利威常用的基本接口。使用本模块可以轻松把保利威 Android 与 iOS SDK 集成到自己的 app 中，实现保利威视频播放、下载等功能。想要集成本插件，需要在[保利威视频云平台](https://www.polyv.net/?f=dcloud_uniapp-211019)注册账号，并开通相关服务。

**注意事项**
- 推荐使用从服务端获取加密串，APP 本地解密的方式（开发者设计自己的加解密方式），通过 ConfigModule 的 setToken 方法进行配置。setConfig 安全性不如 setToken 方式，不推荐使用在正式环境。
* 请务必通过 ConfigModule 的 setViewerId 设置观众ID，观众ID是后台区分用户的唯一标识别，可用于排查问题。
- Android端自v0.1.0+已经解决云打包与uni-app官方原生插件`VideoPlayer（视频播放）`、`Payment（支付）`产生依赖冲突导致云打包失败的问题，**Android端集成请务必同时集成[Polyv播放器插件-Android](https://ext.dcloud.net.cn/plugin?id=4798)**。旧版本可以仍旧解决方案请点击文档说明：[《Android Uni app 插件冲突解决指南》](https://github.com/polyv/polyv-uniapp-cloudclass-plugin-android/wiki/Android-Uni-app-%E6%8F%92%E4%BB%B6%E5%86%B2%E7%AA%81%E8%A7%A3%E5%86%B3%E6%8C%87%E5%8D%97)
- iOS 端自0.1.6+需要同时集成 [Polyv UTDID 插件-iOS](https://ext.dcloud.net.cn/plugin?id=7750)。如果本插件同时集成了 支付模块的支付宝支付 则不需要集成 [Polyv UTDID 插件-iOS] 插件

## 快速使用
### 播放器plv-player
播放器控件为 component，**仅允许在 nvue 中声明使用**。播放器为纯播放器无状态栏皮肤，开发者可自行添加。亦或者下载示例工程，参考使用Demo中提供的皮肤。
```
<plv-player
    ref="vod"
    class="vod-player"
    seekType=0
    autoPlay=true
    disableScreenCAP=false
    rememberLastPosition=false
    @onPlayStatus="onPlayStatus"
    @onPlayError="onPlayError"
    @positionChange="positionChange">
</plv-player>

//js方法，播放vid视频
setVid(){
  this.$refs.vod.setVid({
    vid:'c538856dde5bf6a7419dfeece53f83af_c',
    level:0
  },
  (ret) => {
    if (ret.errMsg != null) {
      uni.showToast({
        title: ret.errMsg,
        icon: "none"
      })
    }
  })
},
```

### 基本模块
通过 uni.requireNativePlugin("ModuleName") 获取 module ，就可以直接调用相关模块接口。目前有三个模块如下代码所示。其中ConfigModule用于点播的初始化，开发者必须在保利威官网注册以后，在点播后台获取到配置信息初始化，播放器才能正式使用。项目模块介绍和接口说明查看下文各模块接口介绍。
```
var configModule = uni.requireNativePlugin("PLV-VodUniPlugin-ConfigModule")
	var infoModule = uni.requireNativePlugin("PLV-VodUniPlugin-InfoModule")
	var downloadModule = uni.requireNativePlugin("PLV-VodUniPlugin-DownloadModule")

//...
	configModule.setToken({
			'userid': '',
			'readtoken': '',
			'writetoken': '',
			'secretkey': ''
		},
		(ret) => {
			if (ret.isSuccess == true) {
				uni.showToast({
					title:'设置token成功',
					icon: "none"
				})
			} else {
				let errMsg = ret.errMsg;
				uni.showToast({
					title:'设置token失败：' + errMsg,
					icon: "none"
				})
			}
		})
```



## 配置模块 - ConfigModule

ConfigModule 封装了账号信息、用户信息配置功能。
开发者要播放保利威视频，需先到 [保利威官网](https://www.polyv.net/?f=dcloud_uniapp-211019) 注册账号，登录账号后，进入**云点播 - 设置 - API接口** 获取 `userid`、 `writetoken`、 `readtoken`、 `secretkey`，并将加密得到加密串放到自己的服务器，再在移动端通过网络获取加密串，app 本地解密，并设置给 `setToken` 方法。

### setConfig

加密串可在保利威官网的**云点播 - 设置 - API接口 - 点击查看临时加密串**获取，本方法使用固定的加密方式，开发者可在开发时使用，但安全性不如 setToken 方式，不推荐使用在正式环境。

**params**

`config`

- 类型：字符串
- 描述：（必选项）临时加密串

`aeskey`

- 类型：字符串
- 描述：（可选项，默认值 VXtlHmwfS2oYm0CZ）加密串的加密密钥

`iv`

- 类型：字符串
- 描述：（可选项，默认值 2u9gDPKdX6GyQJKU）加密串的加密向量

**callback**

`isSuccess`

- 类型：布尔类型
- 描述：是否设置成功

`errMsg`

- 类型：字符串
- 描述：错误信息




### setToken

 `userid`、 `writetoken`、 `readtoken`、 `secretkey`可在保利威官网的**云点播 - 设置 - API接口**获取，推荐用于正式环境。

**params**

`userid`

- 类型：字符串
- 描述：（必选项）保利威账号下的 userid

`readtoken`

- 类型：字符串
- 描述：（必选项）保利威账号下的 readtoke

`writetoken`

- 类型：字符串
- 描述：（必选项）保利威账号下的 writetoken

`secretkey`

- 类型：字符串
- 描述：（必选项）保利威账号下的 secretkey

**callback**

`isSuccess`

- 类型：布尔类型
- 描述：是否设置成功

`errMsg`

- 类型：字符串
- 描述：错误信息



### setViewerId

设置观众ID。

**params**

`viewerId`

- 类型：字符串
- 描述：（必选项）观看日志中的观众ID



### setViewerName

设置观众昵称。

**params**

`viewerName`

- 类型：字符串
- 描述：（必选项）观看日志中的观众昵称



### setViewerInfo

设置观众自定义参数。

**params**

`param3`

- 类型：字符串
- 描述：（可选项）对应观看日志中的 param3

`param4`

- 类型：字符串
- 描述：（可选项）对应观看日志中的 param4

`param5`

- 类型：字符串
- 描述：（可选项）对应观看日志中的 param5



### openMediaCodec

设置播放器为硬解解码播放，默认关闭。该解码模式设置后，会缓存该设置，直到清除数据卸载应用或者重新设置并重启应用后生效。**（Android v0.0.1+ 可用，iOS v0.0.6+ 可用）**

**params**

`mediaCodec`

- 类型：布尔类型
- 描述：（必选项）默认为false软解。true为硬解。



### setRenderView

设置播放器渲染视图类型。**仅限Android使用。**

**params**

`renderViewType`

- 类型：整型数字
- 描述：（必选项）渲染视图类型。1为SurfaceView，2为TextureView（默认）



## 信息模块 - InfoModule

InfoModule 封装了获取保利威视频信息的功能。



### getVideoInfo

通过 vid 获取已发布视频的时长、所支持码率。

**params**

`vid`

- 类型：字符串
- 描述：（必选项）视频的 vid

**callback**

`vid`

- 类型：字符串
- 描述：视频的 vid

`duration`

- 类型：数字类型
- 描述：视频播放时长，单位秒

`levelNum`

- 类型：数字类型
- 描述：视频支持码率。「1-流畅， 2-高清， 3-超清」，如返回 3，表示支持流畅、高清和超清

`errMsg`

- 类型：字符串
- 描述：错误信息



### getFileSize

通过 vid 和指定码率获取已发布视频的文件大小。

**params**

`vid`

- 类型：字符串
- 描述：（必选项）视频的 vid

`level`

- 类型：整型数字
- 描述：（必选项）视频码率

**callback**

`vid`

- 类型：字符串
- 描述：视频的 vid

`fileSize`

- 类型：数字类型
- 描述：视频文件大小，单位字节

`errMsg`

- 类型：字符串
- 描述：错误信息



## 下载模块 - DownloadModule

DownloadModule 封装了保利威的视频下载功能，支持断点下载。最大并发数为3，通过 `addDownloader` 创建下载器之后，需调用 `startDownloader` 或 `startALLDownloader` 开启下载。

**自0.1.0开始，下载状态进度回调需要通过`setListenDownloadStatus`设置，详见下文说明。**

### setListenDownloadStatus
设置下载器下载状态进度回调监听器。离开页面时应当重新置空。

**callback**
  ```json
  {
    vid0: { // 以 vid（字符串） 为键，下载器状态（字典）为值
                  errMsg：// 字符串类型，错误信息
  				downloadStatus:	// 下载状态，字符串类型；回调事件类型，取值范围如下：
  								// ready-下载器准备就绪
  								// downloading-下载中
  								// stopped-下载被停止
  								// failed-下载失败
  								// finished-下载完成
  				downloadPercentage:	// 当前下载进度，数字类型，取值范围为0~100浮点数
  			}
  }
  ```



**example**

```html
//进入页面后设置下载监听，应当在addDownloader之前设置
downloadModule.setListenDownloadStatus(null, result=>{
    downloadStatus = "\n"+JSON.stringify(result)
})

//离开页面后主动注销监听器
downloadModule.setListenDownloadStatus(null,null)
downloadModule.setListenDownloadStatus(null)
```

### addDownloader

通过 vid 和 指定码率 level 创建一个视频下载器，并添加到下载列表。每个 vid 只能下载一个码率，要想下载新的码率的视频，需删除该 vid 已下载的视频，才能添加下载。（需要执行startDownloader或startAllDownloader才会执行下载任务）

**params**

`downloadArr`

- 类型：字典数组

- 描述：（必选项）包含多个需要下载视频的 vid、level 健值对

- 内部字段：

  ```json
  [
  	{
  		vid: // 视频 vid，字符串类型
  		level: // 视频码率，整型数字，取值范围 1-流畅，2-为高清，3-超清，如果设置码率不存在，默认下载最高码率
  	},
  	{
  		vid:
  		level:
  	},
  	...
  ]
  ```

**callback**

- 类型：JSON对象

- 描述：下载器状态列表。本回调函数在下载器开始下载后，下载状态发生变化时执行。

- 版本变更：0.1.0起callback将不再回调downloadStatus、downloadPercentage

- 内部字段：

  ```json
  {
    vid0: { // 以 vid（字符串） 为键，下载器状态（字典）为值
                  errMsg：// 字符串类型，错误信息
  				downloadStatus:	// 下载状态，字符串类型；回调事件类型，取值范围如下：
  								// ready-下载器准备就绪
  								// downloading-下载中
  								// stopped-下载被停止
  								// failed-下载失败
  								// finished-下载完成
  				downloadPercentage:	// 当前下载进度，数字类型，取值范围为0~100浮点数
  			}
  }
  ```



### setDownloadCallbackInterval

设置下载开启之后，`addDownloader` 方法 `downloadStatus` 为 `downloading` 时的回调时间间隔。

**params**

`seconds`

- 类型：数字类型
- 描述：（必选项）间隔时间，单位秒，默认值 1，取值范围须为正实数



### getDownloadList

返回所有下载器，包括下载中、下载成功、下载失败的下载器。

**callback**

- 类型：数组对象

- 描述：下载器列表。本回调函数在下载器开始下载后，下载状态发生变化时执行

- 内部字段：

  ```json
  {
      downloadList：
      [
          {
              vid:	// 视频 vid
              level:	// 视频码率
              duration: //视频时长
              fileSize: //视频文件大小
              title: //视频标题
              progress: //视频已经下载的进度,取值范围为0~100浮点数
          },
          {
              vid:	// 视频 vid
              level:	// 视频码率
            //...
          },
          ...
      ]
  }
  ```



### startDownloader

启动下载器列表中指定下载器的下载。

**params**

`vid`

- 类型：字符串
- 描述：（必选项）视频的 vid

**callback**

`vid`

- 类型：字符串
- 描述：视频的 vid

`errMsg`

- 类型：字符串
- 描述：错误信息



### stopDownloader

停止下载器列表中指定下载器的下载。

**params**

`vid`

- 类型：字符串
- 描述：（必选项）视频的 vid

**callback**

`vid`

- 类型：字符串
- 描述：视频的 vid

`errMsg`

- 类型：字符串
- 描述：错误信息




### deleteVideo

删除指定视频的本地缓存，移除指定视频的下载器，若该视频尚未成功下载，停止下载。

**params**

`vid`

- 类型：字符串
- 描述：（必选项）视频的 vid

**callback**

`vid`

- 类型：字符串
- 描述：视频的 vid

`errMsg`

- 类型：字符串
- 描述：错误信息



### startAllDownloader

启动下载器列表中所有下载器的下载。



### stopAllDownloader

停止下载器列表中所有下载器的下载。



### deleteAllVideo

删除所有已下载视频的本地缓存，清空下载器队列，停止所有下载。




### **isVideoExist**

判断指定码率的视频是否已成功下载并缓存在本地。

**params**

`vid`

- 类型：字符串
- 描述：（必选项）视频的 vid

`level`

- 类型：整型数字
- 描述：（必选项）视频码率

**syn return**

- 类型：JSON对象

  ```json
  {
  	exist:	// 布尔类型，视频是否存在本地，存在为true，反之为false
      errMsg: // 错误描述
  }
  ```



## 播放器组件 - PlayerComponent

播放器组件 PlayerComponent 名称为 plv-player，可通过视频 vid 播放保利威视频，也可通过 URL 播放外网视频。

### 自定义属性

#### seekType

- 类型：整型数字，0 或 1
- 描述：播放定位类型设置，0 默认模式，1 精准模式，默认为 0

#### autoPlay

- 类型：布尔类型
- 描述：是否在设置 vid 后自动开始播放，默认 true

#### disableScreenCAP

- 类型：布尔类型
- 描述：是否开启防录屏功能，true 开启，false 关闭，默认 false

#### rememberLastPosition

- 类型：布尔类型
- 描述：是否开启记忆播放位置，默认 false

### 自定义事件

#### onPlayStatus

`playbackState`

- 类型：字符串
- 描述：「start-开始， pause-暂停， stop-停止，complete-完成」

`preparedToPlay`

- 类型：布尔类型
- 描述：准备就绪为 true，未就绪为 false

#### onPlayError

`errCode`

- 类型：数字类型
- 描述：错误码

`errEvent`

- 类型：字符串

- 描述：错误描述

  ```
  errCode - errEvent
  0 - config_invalid // 未配置加密串
  1 - illegal_vid // 非法播放
  2 - status_error // 视频状态码错误（android独有，iOS包含在play_error中）
  3 - play_error(#code) // 原生SDK错误码
  ```

#### positionChange

`currentPosition`

- 类型：数字类型
- 描述：当前播放位置，单位秒，播放器就绪状态下每隔一秒回调一次



### setVid

设置播放视频的 vid。

**params**

`vid`

- 类型：字符串
- 描述：（必选项）视频的 vid

`level`

- 类型：整型数字
- 描述：（可选项）视频码率，「0 - 自动(默认)，1-流畅， 2-高清， 3-超清」

**callback**

`vid`

- 类型：字符串
- 描述：视频 vid

`errMsg`

- 类型：字符串
- 描述：错误信息



### setURL

设置播放视频的 URL。

**params**

`url`

- 类型：字符串
- 描述：（必选项）视频的 URL

**callback**

`url`

- 类型：字符串
- 描述：视频的 URL

`errMsg`

- 类型：字符串
- 描述：错误信息



### start

开始播放



### pause

暂停播放



### stop

停止播放



### forward

快进

**params**

`seconds`

- 类型：数字类型
- 描述：（必选项）快进的时间，单位秒，必须大于 0



### rewind

快退

**params**

`seconds`

- 类型：数字类型
- 描述：（必选项）快退的时间，单位秒，必须大于 0



### seekTo

跳转

**params**

`seconds`

- 类型：数字类型
- 描述：（必选项）跳转到当前音视频播放的时间，单位秒，必须大于等于 0



### isPlaying

播放器是否正在播放视频。

**callback**

`isPlaying`

- 类型：布尔类型
- 描述：视频是否正在播放



### getLevelNum

播放器当前播放视频所支持码率。

**callback**

`levelNum`

- 类型：数字类型
- 描述：视频支持码率，「1-流畅， 2-高清， 3-超清」，如返回 3，表示支持流畅、高清和超清



### showMarquee

在播放器组件上显示跑马灯。请不要多次调用，否则可能会显示多条跑马灯信息。

**params**

`marquee`

- 类型：字符串
- 描述：（可选项）跑马灯文字，默认值 Polyv Uni-App Plugin

`duration`

- 类型：数字类型
- 描述： （可选项）单次跑马灯显示的时长，单位秒，默认值 5

`interval`

- 类型：数字类型
- 描述：（可选项）两次跑马灯播放间隔的时长，单位秒，默认值 0

`color`

- 类型：字符串
- 描述：（可选项）跑马灯颜色 RGB 值，默认值 0xFFE900

`font`

- 类型：整型数字
- 描述：（可选项）跑马灯字体大小，默认值 16，取值范围 5~72

`alpha`

- 类型：数字类型
- 描述：（可选项）跑马灯透明度，0 - 1 的浮点数，默认值 1，取值范围 0~1



### setVolume

设置播放器音量。

**params**

`volume`

- 类型：数字类型
- 描述： （可选项）音量大小，取值范围 0 ~ 1，默认值 0



### getVolume

获取播放器音量。

**callback**

`volume`

- 类型：数字类型
- 描述：当前播放器音量值，取值范围 0~1



### setSpeed

设置播放器播放速率。

**params**

`speed`

- 类型：数字类型
- 描述： （可选项）播放速率，取值范围 0.5 ~ 2.0，默认值 1.0



### getSpeed

获取播放器当前播放速率。

**callback**

`speed`

- 类型：数字类型
- 描述：当前播放器播放速率



### getCurrentLevel

获取播放器当前播放视频码率。

**callback**

`currentLevel`

- 类型：数字类型
- 描述：当前播放视频码率，取值范围 0-自动，1-流畅， 2-高清， 3-超清



### changeLevel

切换播放器当前播放视频码率

**params**

`level`

- 类型：整型数字
- 描述：（可选项）指定码率，取值范围 0-自动，1-流畅， 2-高清， 3-超清

**callback**

`errMsg`

- 类型：字符串
- 描述：错误信息



### getDuration

获取当前播放器播放视频总时长。

**callback**

`duration`

- 类型：数字类型
- 描述：视频时长，单位秒



### getBufferPercentage

获取当前播放器播放视频缓冲百分比。

**callback**

`bufferPercentage`

- 类型：数字类型
- 描述：视频缓冲百分比，取值范围 0 ~ 100



### getCurrentPosition

获取当前播放器播放视频位置。

**callback**

`currentPosition`

- 类型：数字类型
- 描述：视频当前播放位置，单位秒



### snapshot

保存播放器播放视频当前画面截图到相册，不受播放器属性 disableScreenCAP 影响。



### changeToPortrait

切换屏幕方向到竖屏



### changeToLandscape

切换屏幕方向到横屏



### disableScreenCAP

控制防录屏开关。**仅限Android使用。**

**params**

`disableScreenCAP`

- 类型：布尔类型
- 描述： （必选项）是否开启防录屏功能，true 开启，false 关闭，默认 false

