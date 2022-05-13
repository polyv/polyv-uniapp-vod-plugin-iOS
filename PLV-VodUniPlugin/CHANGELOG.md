# Changelog

本文档用于描述保利威视频云核心产品“云点播”在 uni-app 平台提供的原生 SDK 插件每个版本的更新、修改。
**注意：自0.1.0起Android端集成点播插件，需要同时集成[Polyv播放器插件-Android](https://ext.dcloud.net.cn/plugin?id=4798)**

> 该项目已发布在 uni-app 平台的插件市场。

<!--  Added Changed Removed Fixed -->



## PolyvVodSDK 版本对应
- 0.2.0 - （iOS: 2.16.6, android: 2.16.5)
- 0.1.6 - （iOS: 2.15.1, android: 2.15.1)
- 0.1.5 - （iOS: 2.15.1, android: 2.15.1)
- 0.1.2 - （iOS: 2.15.1, android: 2.15.1)
- 0.1.0 - （iOS: 2.15.0, android: 2.15.1)
- 0.0.4 - （iOS: 2.13.1, android: 2.13.1)
- 0.0.1 - （iOS: 2.11.0, android: 2.13.1)

## 【0.2.0】- 2022-05-07 

### Changed

- 【Android】更新SDK版本至2.16.5;
- 【iOS】更新SDK版本至2.16.6;

### Fixed

- 【Android】修复高版本开发工具打包zip4j库冲突的问题；


## 【0.1.6】- 2022-03-29

### Changed

- 【iOS】移除 UTDID 库；

## 【0.1.5】- 2021-08-16

### Fixed

- 【iOS】修复下载列表在重启应用后获取失败的问题；

  

## 【0.1.2】- 2021-06-04

### Changed

- 【iOS】更新SDK值2.15.1;
- 【iOS】 与安卓端数据逻辑同步；
- 【demo】新增横竖屏切换是隐藏状态栏；
- 【demo】新增下载、播放等演示示例；

### Fixed

- 【iOS】修复下载回调监听获取不到的问题；
- 【iOS】修复解压后的视频下载列表获取不到的问题；





## 【0.1.1】- 2021-05-06

### changed

- 【Android】修复播放器为空的问题
- 【Android】修复同时集成云直播插件导致的云打包兼容问题

## 【0.1.0】- 2021-05-06

### add

- 新增接口：setListenDownloadStatus，可获取下载状态进度，原addDownloader将不再回调。详情见文档说明。
- 【Android】0.1.0起集成此插件必须同时集成[Polyv播放器插件-Android](https://ext.dcloud.net.cn/plugin?id=4798)
- 【Android】解决Android云打包同时集成和VideoPlayer、Payment插件的冲突问题

### Changed

- Android集成点播SDK2.15.1，iOS集成点播2.15.0
- getDownloadList回调更多数据：vid、level、duration、fileSize、title、progress。详细见文档说明



## 【0.0.6】- 2021-04-02

### Changed

- iOS 插件默认使用软解，并提供软硬解开关，与 android 插件对齐。



## 【0.0.5】- 2021-02-04

### Changed

- 升级 iOS uni-app SDK 到 3.0.5，修复 HBuilderx 3.0+ 云打包时兼容问题。



## 【0.0.4】- 2020-11-20

### Changed

- 升级 iOS 点播 SDK，修复与 uniapp 模块 videoPlayer 的冲突；
  （Android同时与VideoPlayer集成云打包会失败）



## 【0.0.3】- 2020-11-05

### Added

- 添加`changeToLandscape`、`changeToPortrait`方法
- 示例工程添加播放器皮肤示例



## 【0.0.2】- 2020-10-09

### Changed

- 修改插件ID



## 【0.0.1】- 2020-09-21

### Added

- 集成 iOS 点播 SDK 2.11.0，android 点播 SDK 2.13.1
