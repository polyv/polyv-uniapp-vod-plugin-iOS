# Framework 版本记录

## [0.2.0]-- PolyvVodSDK 2.16.6

```
PLVVodUniPlugin  
对应的 sdk: 
PolyvVodSDK 2.16.6

PolyvAliHttpDNS v1.8.0
包含：AlicloudHttpDNS、AlicloudUtils 两个 framework

PLVIJKPlayer v0.11.1(dynamically)
包含：PLVIJKPlayer.framework

WCDB v1.0.7.5 (dynamically)
包含：sqlcipher.framework、WCDB.framework sqliterk.framework
```

## 

## [0.1.6]-- PolyvVodSDK 2.15.1

```
PLVVodUniPlugin  

对应的 sdk: 
PolyvVodSDK 2.15.1

PolyvAliHttpDNS v1.8.0
包含：AlicloudHttpDNS、AlicloudUtils 两个 framework

PolyvIJKPlayer v0.9.4(dynamically)
包含：PolyvIJKMediaFramework.framework

WCDB v1.0.7.5 (dynamically)
包含：sqlcipher.framework、WCDB.framework sqliterk.framework
```

## [0.1.2、0.1.3、0.1.5]-- PolyvVodSDK 2.15.1

```
PLVVodUniPlugin  

对应的 sdk: 
PolyvVodSDK 2.15.1

PolyvAliHttpDNS v1.8.0
包含：AlicloudHttpDNS、AlicloudUtils、UTDID 三个 framework

PolyvIJKPlayer v0.9.4(dynamically)
包含：PolyvIJKMediaFramework.framework

WCDB v1.0.7.5 (dynamically)
包含：sqlcipher.framework、WCDB.framework sqliterk.framework
```

##   [0.1.0]-- PolyvVodSDK 2.15.0

**切换为CocoaPods版本维护** 

```
PLVVodUniPlugin 0.1.0版本 对应的 sdk

PolyvVodSDK 2.15.0

PolyvAliHttpDNS v1.8.0
包含：AlicloudHttpDNS、AlicloudUtils、UTDID 三个 framework

PolyvIJKPlayer v0.9.3
包含：PolyvIJKMediaFramework.framework

WCDB v1.0.7.5 (dynamically)
包含：sqlcipher.framework、WCDB.framework 
```



## [0.0.4 ~ ] - PolyvVodSDK 2.13.1

PolyvAliHttpDNS v1.7.3
包含：AlicloudHttpDNS、AlicloudUtils、UTDID 三个 framework

PolyvIJKPlayer v0.9.1
包含：PolyvIJKMediaFramework.framework

WCDB v1.0.7.5
包含：sqlcipher.framework、WCDB.framework 



## [0.0.1 ~ 0.0.3] - PolyvVodSDK 2.11.0

PolyvAliHttpDNS v1.7.3
包含：AlicloudHttpDNS、AlicloudUtils、UTDID 三个 framework

PolyvIJKPlayer v0.8.0
包含：PolyvIJKMediaFramework.framework

WCDB v1.0.7.5
包含：sqlcipher.framework、WCDB.framework 



### 离线打包异常问题汇总

##### 1、“dyld: Library not loaded” Reason: image not found

 解决

> 在TARGETS->选择target->General-> Framework,Libraries,and Embedded Content下下，设置该Framework  Embed & sign。

如下图:

![img](/Users/Sakya/Desktop/Company/开发文档/Source/webp.png)

##### 2、Building for iOS Simulator, but the linked and embedded framework was built for iOS + iOS Simulator

解决

> 通过修改项目配置里面的**Validate Workspace**为**Yes**后，重新编译则报错消失。

![img](/Users/Sakya/Desktop/Company/开发文档/Source/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2d1b3lvbmdtaW5nOTI1,size_16,color_FFFFFF,t_70.png)

Validate Workspace的配置说明：

> If enabled, perform validation checks on the workspace configuration as part of the build process. 
>
> 如果开启了（设置为Yes），那么在构建版本的过程中将对工作区配置进行验证检查。





```
error: https://service.dcloud.net.cn/build/errorLog/676e7360-c4db-11eb-88fa-5f9a8e79cadf

https://service.dcloud.net.cn/build/errorLog/6e6e3ab0-c4df-11eb-b33d-098af2b102c2
```

