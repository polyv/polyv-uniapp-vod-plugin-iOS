!function(t){var e={};function n(o){if(e[o])return e[o].exports;var i=e[o]={i:o,l:!1,exports:{}};return t[o].call(i.exports,i,i.exports,n),i.l=!0,i.exports}n.m=t,n.c=e,n.d=function(t,e,o){n.o(t,e)||Object.defineProperty(t,e,{enumerable:!0,get:o})},n.r=function(t){"undefined"!=typeof Symbol&&Symbol.toStringTag&&Object.defineProperty(t,Symbol.toStringTag,{value:"Module"}),Object.defineProperty(t,"__esModule",{value:!0})},n.t=function(t,e){if(1&e&&(t=n(t)),8&e)return t;if(4&e&&"object"==typeof t&&t&&t.__esModule)return t;var o=Object.create(null);if(n.r(o),Object.defineProperty(o,"default",{enumerable:!0,value:t}),2&e&&"string"!=typeof t)for(var i in t)n.d(o,i,function(e){return t[e]}.bind(null,i));return o},n.n=function(t){var e=t&&t.__esModule?function(){return t.default}:function(){return t};return n.d(e,"a",e),e},n.o=function(t,e){return Object.prototype.hasOwnProperty.call(t,e)},n.p="",n(n.s=80)}({0:function(t,e,n){"use strict";function o(t,e,n,o,i,r,a,s,u,l){var c,p="function"==typeof t?t.options:t;if(u){p.components||(p.components={});var f=Object.prototype.hasOwnProperty;for(var d in u)f.call(u,d)&&!f.call(p.components,d)&&(p.components[d]=u[d])}if(l&&((l.beforeCreate||(l.beforeCreate=[])).unshift((function(){this[l.__module]=this})),(p.mixins||(p.mixins=[])).push(l)),e&&(p.render=e,p.staticRenderFns=n,p._compiled=!0),o&&(p.functional=!0),r&&(p._scopeId="data-v-"+r),a?(c=function(t){(t=t||this.$vnode&&this.$vnode.ssrContext||this.parent&&this.parent.$vnode&&this.parent.$vnode.ssrContext)||"undefined"==typeof __VUE_SSR_CONTEXT__||(t=__VUE_SSR_CONTEXT__),i&&i.call(this,t),t&&t._registeredComponents&&t._registeredComponents.add(a)},p._ssrRegister=c):i&&(c=s?function(){i.call(this,this.$root.$options.shadowRoot)}:i),c)if(p.functional){p._injectStyles=c;var g=p.render;p.render=function(t,e){return c.call(e),g(t,e)}}else{var y=p.beforeCreate;p.beforeCreate=y?[].concat(y,c):[c]}return{exports:t,options:p}}n.d(e,"a",(function(){return o}))},1:function(t,e){t.exports={"uni-icon":{fontFamily:"uniicons",fontWeight:"normal"},"uni-bg-red":{backgroundColor:"#F76260",color:"#FFFFFF"},"uni-bg-green":{backgroundColor:"#09BB07",color:"#FFFFFF"},"uni-bg-blue":{backgroundColor:"#007AFF",color:"#FFFFFF"},"uni-container":{flex:1,paddingTop:"15",paddingRight:"15",paddingBottom:"15",paddingLeft:"15",backgroundColor:"#f8f8f8"},"uni-padding-lr":{paddingLeft:"15",paddingRight:"15"},"uni-padding-tb":{paddingTop:"15",paddingBottom:"15"},"uni-header-logo":{paddingTop:"15",paddingRight:"15",paddingBottom:"15",paddingLeft:"15",flexDirection:"column",justifyContent:"center",alignItems:"center",marginTop:"10upx"},"uni-header-image":{width:"80",height:"80"},"uni-hello-text":{marginBottom:"20"},"hello-text":{color:"#7A7E83",fontSize:"14",lineHeight:"20"},"hello-link":{color:"#7A7E83",fontSize:"14",lineHeight:"20"},"uni-panel":{marginBottom:"12"},"uni-panel-h":{backgroundColor:"#ffffff",flexDirection:"row",alignItems:"center",paddingTop:"12",paddingRight:"12",paddingBottom:"12",paddingLeft:"12"},"uni-panel-h-on":{backgroundColor:"#f0f0f0"},"uni-panel-text":{flex:1,color:"#000000",fontSize:"14",fontWeight:"normal"},"uni-panel-icon":{marginLeft:"15",color:"#999999",fontSize:"14",fontWeight:"normal",transform:"rotate(0deg)",transitionDuration:0,transitionProperty:"transform"},"@TRANSITION":{"uni-panel-icon":{duration:0,property:"transform"}},"uni-panel-icon-on":{transform:"rotate(180deg)"},"uni-navigate-item":{flexDirection:"row",alignItems:"center",backgroundColor:"#FFFFFF",borderTopStyle:"solid",borderTopColor:"#f0f0f0",borderTopWidth:"1",paddingTop:"12",paddingRight:"12",paddingBottom:"12",paddingLeft:"12","backgroundColor:active":"#f8f8f8"},"uni-navigate-text":{flex:1,color:"#000000",fontSize:"14",fontWeight:"normal"},"uni-navigate-icon":{marginLeft:"15",color:"#999999",fontSize:"14",fontWeight:"normal"},"uni-list-cell":{position:"relative",flexDirection:"row",justifyContent:"flex-start",alignItems:"center"},"uni-list-cell-pd":{paddingTop:"22upx",paddingRight:"30upx",paddingBottom:"22upx",paddingLeft:"30upx"},"flex-r":{flexDirection:"row"},"flex-c":{flexDirection:"column"},"a-i-c":{alignItems:"center"},"j-c-c":{justifyContent:"center"},"list-item":{flexDirection:"row",paddingTop:"10",paddingRight:"10",paddingBottom:"10",paddingLeft:"10"}}},2:function(t,e,n){"use strict";n.r(e);var o=n(3),i=n.n(o);for(var r in o)"default"!==r&&function(t){n.d(e,t,(function(){return o[t]}))}(r);e.default=i.a},26:function(t,e,n){"use strict";n.r(e);var o=n(5),i=n(2);for(var r in i)"default"!==r&&function(t){n.d(e,t,(function(){return i[t]}))}(r);var a=n(0);var s=Object(a.a)(i.default,o.b,o.c,!1,null,null,"19dd689a",!1,o.a,void 0);(function(t){this.options.style||(this.options.style={}),Vue.prototype.__merge_style&&Vue.prototype.__$appStyle__&&Vue.prototype.__merge_style(Vue.prototype.__$appStyle__,this.options.style),Vue.prototype.__merge_style?Vue.prototype.__merge_style(n(9).default,this.options.style):Object.assign(this.options.style,n(9).default)}).call(s),e.default=s.exports},3:function(t,e,n){"use strict";Object.defineProperty(e,"__esModule",{value:!0}),e.default=void 0;e.default={name:"page-head",props:["title"],data:function(){return{title:this.title}}}},36:function(t,e,n){"use strict";var o=n(59),i=n(51),r=n(0);var a=Object(r.a)(i.default,o.b,o.c,!1,null,null,"1162aa10",!1,o.a,void 0);(function(t){this.options.style||(this.options.style={}),Vue.prototype.__merge_style&&Vue.prototype.__$appStyle__&&Vue.prototype.__merge_style(Vue.prototype.__$appStyle__,this.options.style),Vue.prototype.__merge_style?Vue.prototype.__merge_style(n(74).default,this.options.style):Object.assign(this.options.style,n(74).default)}).call(a),e.default=a.exports},4:function(t,e){t.exports={"page-head":{height:"140rpx"},title__text:{position:"absolute",textAlign:"center",height:"60rpx",left:0,right:0,bottom:0}}},5:function(t,e,n){"use strict";n.d(e,"b",(function(){return o})),n.d(e,"c",(function(){return i})),n.d(e,"a",(function(){}));var o=function(){var t=this.$createElement,e=this._self._c||t;return e("view",{staticClass:["page-head"]},[e("u-text",{staticClass:["title__text"]},[this._v(this._s(this.title))])])},i=[]},51:function(t,e,n){"use strict";var o=n(52),i=n.n(o);e.default=i.a},52:function(t,e,n){"use strict";(function(t){Object.defineProperty(e,"__esModule",{value:!0}),e.default=void 0;var o,i=(o=n(26))&&o.__esModule?o:{default:o};var r=!1,a={components:{Head:i.default},data:function(){return{title:"\u64ad\u653e\u5668\u7ec4\u4ef6",progress:"CurrentPosition\uff1a",videoVid:"e97dbe3e6492b053bc9b5afc677a1394_e"}},onLoad:function(){this},methods:{back:function(){uni.navigateBack()},onVidInput:function(t){this.videoVid=t.detail.value},onPlayError:function(e){null!=e.detail.errEvent&&(t("log",e.detail.errEvent," at pages/sample/ext-component.nvue:80"),uni.showToast({title:"playErrorEvent - "+e.detail.errEvent,icon:"none"}))},positionChange:function(t){this.progress="CurrentPosition\uff1a"+t.detail.currentPosition},onPlayStatus:function(e){null!=e.detail.playbackState?uni.showToast({title:"playbackState - "+e.detail.playbackState,icon:"none"}):null!=e.detail.preparedToPlay&&(t("log","preparedToPlay - "+e.detail.preparedToPlay," at pages/sample/ext-component.nvue:97"),uni.showToast({title:"preparedToPlay - "+e.detail.preparedToPlay,icon:"none"}))},fullScreen:function(){plus.screen.unlockOrientation(),plus.screen.lockOrientation("landscape"),uni.getScreenBrightness({success:function(e){t("log","\u5c4f\u5e55\u4eae\u5ea6\u503c\uff1a"+e.value," at pages/sample/ext-component.nvue:109")}})},cancelFullScreen:function(){plus.screen.unlockOrientation(),plus.screen.lockOrientation("portrait-primary"),uni.setScreenBrightness({value:.2,success:function(){t("log","success"," at pages/sample/ext-component.nvue:119")}})},snapshot:function(){this.$refs.vod.snapshot(null,(function(e){null!=e.errMsg&&t("log",e.errMsg," at pages/sample/ext-component.nvue:126")}))},setVid:function(){this.$refs.vod.setVid({vid:this.videoVid,level:0},(function(t){null!=t.errMsg&&uni.showToast({title:t.errMsg,icon:"none"})}))},setURL:function(){this.$refs.vod.setURL({url:"https://vfx.mtime.cn/Video/2019/02/04/mp4/190204084208765161.mp4"},(function(t){null!=t.errMsg&&uni.showToast({title:t.errMsg,icon:"none"})}))},showMarquee:function(){this.$refs.vod.showMarquee()},startVideo:function(){this.$refs.vod.start()},pauseVideo:function(){this.$refs.vod.pause()},stopVideo:function(){this.$refs.vod.stop()},getDuration:function(){this.$refs.vod.getDuration(null,(function(t){uni.showToast({title:"duration: "+t.duration,icon:"none"})}))},getCurrentPosition:function(){this.$refs.vod.getCurrentPosition(null,(function(e){t("log","---currentPosition: "+e.currentPosition," at pages/sample/ext-component.nvue:182"),uni.showToast({title:"currentPosition: "+e.currentPosition,icon:"none"})}))},getBufferPercentage:function(){this.$refs.vod.getBufferPercentage(null,(function(e){t("log","bufferPercentage: "+e.bufferPercentage," at pages/sample/ext-component.nvue:192"),uni.showToast({title:"bufferPercentage: "+e.bufferPercentage,icon:"none"})}))},isPlaying:function(){this.$refs.vod.isPlaying(null,(function(t){uni.showToast({title:"isPlaying: "+t.isPlaying,icon:"none"})}))},forward:function(){this.$refs.vod.forward({seconds:10})},rewind:function(){this.$refs.vod.rewind({seconds:10})},seekTo:function(){t("log","seekTo: 50"," at pages/sample/ext-component.nvue:214"),this.$refs.vod.seekTo({seconds:50})},setSpeed:function(){this.$refs.vod.setSpeed({speed:1.5})},getSpeed:function(){this.$refs.vod.getSpeed(null,(function(t){uni.showToast({title:"speed: "+t.speed,icon:"none"})}))},changeLevel:function(){this.$refs.vod.changeLevel({level:1})},getCurrentLevel:function(){this.$refs.vod.getCurrentLevel(null,(function(t){uni.showToast({title:"currentLevel: "+t.currentLevel,icon:"none"})}))},getLevelNum:function(){this.$refs.vod.getLevelNum(null,(function(t){uni.showToast({title:"levelNum: "+t.levelNum,icon:"none"})}))},disableScreenCAP:function(){r=!r,this.$refs.vod.disableScreenCAP({disableScreenCAP:r}),uni.showToast({title:"\u9632\u5f55\u5c4f\u5f00\u5173: "+r,icon:"none"})}}};e.default=a}).call(this,n(8).default)},53:function(t,e){t.exports={title:{height:"140rpx"},"vod-player":{height:"300",backgroundColor:"#333333"},"plv-vod-player":{flex:1}}},59:function(t,e,n){"use strict";n.d(e,"b",(function(){return o})),n.d(e,"c",(function(){return i})),n.d(e,"a",(function(){}));var o=function(){var t=this,e=t.$createElement,n=t._self._c||e;return n("scroll-view",{staticStyle:{flexDirection:"column"},attrs:{scrollY:!0,showScrollbar:!0,enableBackToTop:!0,bubble:"true"}},[n("div",[n("head",{staticClass:["title"],attrs:{title:t.title}}),n("view",{staticClass:["vod-player"]},[n("plv-player",{ref:"vod",staticClass:["plv-vod-player"],attrs:{seekType:"0",autoPlay:"true",disableScreenCAP:"false",rememberLastPosition:"false"},on:{onPlayStatus:t.onPlayStatus,onPlayError:t.onPlayError,positionChange:t.positionChange}}),n("button",{staticStyle:{width:"180px",height:"44px",position:"absolute",bottom:"0px",left:"0px"},attrs:{type:"primary"},on:{click:function(e){t.fullScreen()}}},[t._v("\u5168\u5c4f")]),n("button",{staticStyle:{width:"180px",height:"44px",position:"absolute",bottom:"0px",right:"0px"},attrs:{type:"primary"},on:{click:function(e){t.cancelFullScreen()}}},[t._v("\u53d6\u6d88\u5168\u5c4f")]),n("button",{staticStyle:{width:"120px",height:"44px",position:"absolute",top:"0px",right:"0px"},attrs:{type:"primary"},on:{click:function(e){t.snapshot()}}},[t._v("\u622a\u56fe")])],1),n("view",[n("u-text",[t._v(t._s(t.progress))]),n("view",[n("u-input",{staticClass:["uni-input"],staticStyle:{minHeight:"35px",height:"35px",border:"1px solid #cccccc",fontSize:"14px"},attrs:{value:t.videoVid,placeholder:"\u8bf7\u8f93\u5165\u89c6\u9891vid"},on:{input:t.onVidInput}}),n("button",{attrs:{type:"primary"},on:{click:function(e){t.setVid()}}},[t._v("setVid")])],1),n("button",{attrs:{type:"primary"},on:{click:function(e){t.setURL()}}},[t._v("setURL")]),n("button",{attrs:{type:"primary"},on:{click:function(e){t.showMarquee()}}},[t._v("\u663e\u793a\u8dd1\u9a6c\u706f")]),n("button",{attrs:{type:"primary"},on:{click:function(e){t.getBufferPercentage()}}},[t._v("getBufferPercentage")]),n("button",{attrs:{type:"primary"},on:{click:function(e){t.seekTo()}}},[t._v("seekTo 50\u79d2")]),n("button",{attrs:{type:"primary"},on:{click:function(e){t.getCurrentPosition()}}},[t._v("\u5f53\u524d\u8fdb\u5ea6")]),n("button",{attrs:{type:"primary"},on:{click:function(e){t.getDuration()}}},[t._v("getDuration")]),n("button",{attrs:{type:"primary"},on:{click:function(e){t.startVideo()}}},[t._v("\u5f00\u59cb")]),n("button",{attrs:{type:"primary"},on:{click:function(e){t.pauseVideo()}}},[t._v("\u6682\u505c")]),n("button",{attrs:{type:"primary"},on:{click:function(e){t.stopVideo()}}},[t._v("\u505c\u6b62")]),n("button",{attrs:{type:"primary"},on:{click:function(e){t.isPlaying()}}},[t._v("isPlaying")]),n("button",{attrs:{type:"primary"},on:{click:function(e){t.forward()}}},[t._v("\u524d\u8fdb10\u79d2")]),n("button",{attrs:{type:"primary"},on:{click:function(e){t.rewind()}}},[t._v("\u540e\u900010\u79d2")]),n("button",{attrs:{type:"primary"},on:{click:function(e){t.setSpeed()}}},[t._v("1.5x\u500d\u901f\u64ad\u653e")]),n("button",{attrs:{type:"primary"},on:{click:function(e){t.getSpeed()}}},[t._v("\u5f53\u524d\u500d\u901f")]),n("button",{attrs:{type:"primary"},on:{click:function(e){t.changeLevel()}}},[t._v("\u5207\u6362\u7801\u7387\u52301")]),n("button",{attrs:{type:"primary"},on:{click:function(e){t.getCurrentLevel()}}},[t._v("\u83b7\u53d6\u5f53\u524d\u7801\u7387")]),n("button",{attrs:{type:"primary"},on:{click:function(e){t.getLevelNum()}}},[t._v("\u83b7\u53d6\u652f\u6301\u7801\u7387")]),n("button",{attrs:{type:"primary"},on:{click:function(e){t.disableScreenCAP()}}},[t._v("\u9632\u5f55\u5c4f")])],1)],1)])},i=[]},6:function(t,e,n){Vue.prototype.__$appStyle__={},Vue.prototype.__merge_style&&Vue.prototype.__merge_style(n(7).default,Vue.prototype.__$appStyle__)},7:function(t,e,n){"use strict";n.r(e);var o=n(1),i=n.n(o);for(var r in o)"default"!==r&&function(t){n.d(e,t,(function(){return o[t]}))}(r);e.default=i.a},74:function(t,e,n){"use strict";n.r(e);var o=n(53),i=n.n(o);for(var r in o)"default"!==r&&function(t){n.d(e,t,(function(){return o[t]}))}(r);e.default=i.a},8:function(t,e,n){"use strict";function o(t){var e=Object.prototype.toString.call(t);return e.substring(8,e.length-1)}function i(){return"string"==typeof __channelId__&&__channelId__}function r(t,e){switch(o(e)){case"Function":return"function() { [native code] }";default:return e}}Object.defineProperty(e,"__esModule",{value:!0}),e.log=function(t){for(var e=arguments.length,n=new Array(e>1?e-1:0),o=1;o<e;o++)n[o-1]=arguments[o];console[t].apply(console,n)},e.default=function(){for(var t=arguments.length,e=new Array(t),n=0;n<t;n++)e[n]=arguments[n];var a=e.shift();if(i())return e.push(e.pop().replace("at ","uni-app:///")),console[a].apply(console,e);var s=e.map((function(t){var e=Object.prototype.toString.call(t).toLowerCase();if("[object object]"===e||"[object array]"===e)try{t="---BEGIN:JSON---"+JSON.stringify(t,r)+"---END:JSON---"}catch(n){t=e}else if(null===t)t="---NULL---";else if(void 0===t)t="---UNDEFINED---";else{var n=o(t).toUpperCase();t="NUMBER"===n||"BOOLEAN"===n?"---BEGIN:"+n+"---"+t+"---END:"+n+"---":String(t)}return t})),u="";if(s.length>1){var l=s.pop();u=s.join("---COMMA---"),0===l.indexOf(" at ")?u+=l:u+="---COMMA---"+l}else u=s[0];console[a](u)}},80:function(t,e,n){"use strict";n.r(e);n(6);var o=n(36);"undefined"==typeof Promise||Promise.prototype.finally||(Promise.prototype.finally=function(t){var e=this.constructor;return this.then((function(n){return e.resolve(t()).then((function(){return n}))}),(function(n){return e.resolve(t()).then((function(){throw n}))}))}),o.default.mpType="page",o.default.route="pages/sample/ext-component",o.default.el="#root",new Vue(o.default)},9:function(t,e,n){"use strict";n.r(e);var o=n(4),i=n.n(o);for(var r in o)"default"!==r&&function(t){n.d(e,t,(function(){return o[t]}))}(r);e.default=i.a}});