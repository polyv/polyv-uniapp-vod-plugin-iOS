!function(t){var e={};function n(o){if(e[o])return e[o].exports;var i=e[o]={i:o,l:!1,exports:{}};return t[o].call(i.exports,i,i.exports,n),i.l=!0,i.exports}n.m=t,n.c=e,n.d=function(t,e,o){n.o(t,e)||Object.defineProperty(t,e,{enumerable:!0,get:o})},n.r=function(t){"undefined"!=typeof Symbol&&Symbol.toStringTag&&Object.defineProperty(t,Symbol.toStringTag,{value:"Module"}),Object.defineProperty(t,"__esModule",{value:!0})},n.t=function(t,e){if(1&e&&(t=n(t)),8&e)return t;if(4&e&&"object"==typeof t&&t&&t.__esModule)return t;var o=Object.create(null);if(n.r(o),Object.defineProperty(o,"default",{enumerable:!0,value:t}),2&e&&"string"!=typeof t)for(var i in t)n.d(o,i,function(e){return t[e]}.bind(null,i));return o},n.n=function(t){var e=t&&t.__esModule?function(){return t.default}:function(){return t};return n.d(e,"a",e),e},n.o=function(t,e){return Object.prototype.hasOwnProperty.call(t,e)},n.p="",n(n.s=51)}([function(t,e,n){"use strict";function o(t,e,n,o,i,r,l,s,a,u){var p,c="function"==typeof t?t.options:t;if(a){c.components||(c.components={});var f=Object.prototype.hasOwnProperty;for(var h in a)f.call(a,h)&&!f.call(c.components,h)&&(c.components[h]=a[h])}if(u&&((u.beforeCreate||(u.beforeCreate=[])).unshift((function(){this[u.__module]=this})),(c.mixins||(c.mixins=[])).push(u)),e&&(c.render=e,c.staticRenderFns=n,c._compiled=!0),o&&(c.functional=!0),r&&(c._scopeId="data-v-"+r),l?(p=function(t){(t=t||this.$vnode&&this.$vnode.ssrContext||this.parent&&this.parent.$vnode&&this.parent.$vnode.ssrContext)||"undefined"==typeof __VUE_SSR_CONTEXT__||(t=__VUE_SSR_CONTEXT__),i&&i.call(this,t),t&&t._registeredComponents&&t._registeredComponents.add(l)},c._ssrRegister=p):i&&(p=s?function(){i.call(this,this.$root.$options.shadowRoot)}:i),p)if(c.functional){c._injectStyles=p;var d=c.render;c.render=function(t,e){return p.call(e),d(t,e)}}else{var v=c.beforeCreate;c.beforeCreate=v?[].concat(v,p):[p]}return{exports:t,options:c}}n.d(e,"a",(function(){return o}))},function(t,e){t.exports={"uni-icon":{fontFamily:"uniicons",fontWeight:"normal"},"uni-bg-red":{backgroundColor:"#F76260",color:"#FFFFFF"},"uni-bg-green":{backgroundColor:"#09BB07",color:"#FFFFFF"},"uni-bg-blue":{backgroundColor:"#007AFF",color:"#FFFFFF"},"uni-container":{flex:1,paddingTop:"15",paddingRight:"15",paddingBottom:"15",paddingLeft:"15",backgroundColor:"#f8f8f8"},"uni-padding-lr":{paddingLeft:"15",paddingRight:"15"},"uni-padding-tb":{paddingTop:"15",paddingBottom:"15"},"uni-header-logo":{paddingTop:"15",paddingRight:"15",paddingBottom:"15",paddingLeft:"15",flexDirection:"column",justifyContent:"center",alignItems:"center",marginTop:"10upx"},"uni-header-image":{width:"80",height:"80"},"uni-hello-text":{marginBottom:"20"},"hello-text":{color:"#7A7E83",fontSize:"14",lineHeight:"20"},"hello-link":{color:"#7A7E83",fontSize:"14",lineHeight:"20"},"uni-panel":{marginBottom:"12"},"uni-panel-h":{backgroundColor:"#ffffff",flexDirection:"row",alignItems:"center",paddingTop:"12",paddingRight:"12",paddingBottom:"12",paddingLeft:"12"},"uni-panel-h-on":{backgroundColor:"#f0f0f0"},"uni-panel-text":{flex:1,color:"#000000",fontSize:"14",fontWeight:"normal"},"uni-panel-icon":{marginLeft:"15",color:"#999999",fontSize:"14",fontWeight:"normal",transform:"rotate(0deg)",transitionDuration:0,transitionProperty:"transform"},"@TRANSITION":{"uni-panel-icon":{duration:0,property:"transform"}},"uni-panel-icon-on":{transform:"rotate(180deg)"},"uni-navigate-item":{flexDirection:"row",alignItems:"center",backgroundColor:"#FFFFFF",borderTopStyle:"solid",borderTopColor:"#f0f0f0",borderTopWidth:"1",paddingTop:"12",paddingRight:"12",paddingBottom:"12",paddingLeft:"12","backgroundColor:active":"#f8f8f8"},"uni-navigate-text":{flex:1,color:"#000000",fontSize:"14",fontWeight:"normal"},"uni-navigate-icon":{marginLeft:"15",color:"#999999",fontSize:"14",fontWeight:"normal"},"uni-list-cell":{position:"relative",flexDirection:"row",justifyContent:"flex-start",alignItems:"center"},"uni-list-cell-pd":{paddingTop:"22upx",paddingRight:"30upx",paddingBottom:"22upx",paddingLeft:"30upx"},"flex-r":{flexDirection:"row"},"flex-c":{flexDirection:"column"},"a-i-c":{alignItems:"center"},"j-c-c":{justifyContent:"center"},"list-item":{flexDirection:"row",paddingTop:"10",paddingRight:"10",paddingBottom:"10",paddingLeft:"10"}}},function(t,e,n){"use strict";n.r(e);var o=n(3),i=n.n(o);for(var r in o)"default"!==r&&function(t){n.d(e,t,(function(){return o[t]}))}(r);e.default=i.a},function(t,e,n){"use strict";Object.defineProperty(e,"__esModule",{value:!0}),e.default=void 0;e.default={name:"page-head",props:["title"],data:function(){return{title:this.title}}}},function(t,e){t.exports={"page-head":{height:"140rpx"},title__text:{position:"absolute",textAlign:"center",height:"60rpx",left:0,right:0,bottom:0}}},function(t,e,n){"use strict";n.d(e,"b",(function(){return o})),n.d(e,"c",(function(){return i})),n.d(e,"a",(function(){}));var o=function(){var t=this.$createElement,e=this._self._c||t;return e("view",{staticClass:["page-head"]},[e("u-text",{staticClass:["title__text"]},[this._v(this._s(this.title))])])},i=[]},function(t,e,n){"use strict";n.r(e);var o=n(4),i=n.n(o);for(var r in o)"default"!==r&&function(t){n.d(e,t,(function(){return o[t]}))}(r);e.default=i.a},function(t,e,n){Vue.prototype.__$appStyle__={},Vue.prototype.__merge_style&&Vue.prototype.__merge_style(n(8).default,Vue.prototype.__$appStyle__)},function(t,e,n){"use strict";n.r(e);var o=n(1),i=n.n(o);for(var r in o)"default"!==r&&function(t){n.d(e,t,(function(){return o[t]}))}(r);e.default=i.a},function(t,e,n){"use strict";n.r(e);var o=n(5),i=n(2);for(var r in i)"default"!==r&&function(t){n.d(e,t,(function(){return i[t]}))}(r);var l=n(0);var s=Object(l.a)(i.default,o.b,o.c,!1,null,null,"06194662",!1,o.a,void 0);(function(t){this.options.style||(this.options.style={}),Vue.prototype.__merge_style&&Vue.prototype.__$appStyle__&&Vue.prototype.__merge_style(Vue.prototype.__$appStyle__,this.options.style),Vue.prototype.__merge_style?Vue.prototype.__merge_style(n(6).default,this.options.style):Object.assign(this.options.style,n(6).default)}).call(s),e.default=s.exports},function(t,e,n){"use strict";function o(t){var e=Object.prototype.toString.call(t);return e.substring(8,e.length-1)}function i(){return"string"==typeof __channelId__&&__channelId__}function r(t,e){switch(o(e)){case"Function":return"function() { [native code] }";default:return e}}Object.defineProperty(e,"__esModule",{value:!0}),e.log=function(t){for(var e=arguments.length,n=new Array(e>1?e-1:0),o=1;o<e;o++)n[o-1]=arguments[o];console[t].apply(console,n)},e.default=function(){for(var t=arguments.length,e=new Array(t),n=0;n<t;n++)e[n]=arguments[n];var l=e.shift();if(i())return e.push(e.pop().replace("at ","uni-app:///")),console[l].apply(console,e);var s=e.map((function(t){var e=Object.prototype.toString.call(t).toLowerCase();if("[object object]"===e||"[object array]"===e)try{t="---BEGIN:JSON---"+JSON.stringify(t,r)+"---END:JSON---"}catch(n){t=e}else if(null===t)t="---NULL---";else if(void 0===t)t="---UNDEFINED---";else{var n=o(t).toUpperCase();t="NUMBER"===n||"BOOLEAN"===n?"---BEGIN:"+n+"---"+t+"---END:"+n+"---":String(t)}return t})),a="";if(s.length>1){var u=s.pop();a=s.join("---COMMA---"),0===u.indexOf(" at ")?a+=u:a+="---COMMA---"+u}else a=s[0];console[l](a)}},function(t,e,n){"use strict";var o=n(40),i=n(15),r=n(0);var l=Object(r.a)(i.default,o.b,o.c,!1,null,null,"0ad0f3a4",!1,o.a,void 0);(function(t){this.options.style||(this.options.style={}),Vue.prototype.__merge_style&&Vue.prototype.__$appStyle__&&Vue.prototype.__merge_style(Vue.prototype.__$appStyle__,this.options.style),Vue.prototype.__merge_style?Vue.prototype.__merge_style(n(49).default,this.options.style):Object.assign(this.options.style,n(49).default)}).call(l),e.default=l.exports},,,,function(t,e,n){"use strict";var o=n(16),i=n.n(o);e.default=i.a},function(t,e,n){"use strict";(function(t){Object.defineProperty(e,"__esModule",{value:!0}),e.default=void 0;var o=r(n(9)),i=r(n(52));function r(t){return t&&t.__esModule?t:{default:t}}weex.requireModule("dom");var l={components:{Skin:i.default,Head:o.default},onReady:function(){this.vodPlayer=this.$refs.vod,this.skin=this.$refs.skin,this.setVid(),plus.screen.lockOrientation("portrait-primary")},data:function(){return{title:"\u64ad\u653e\u5668Demo",vodPlayer:null,skin:null,isFull:!1,defaultVolume:.5}},methods:{setVid:function(){var t=this;this.vodPlayer.setVid({vid:"c538856dde5bf6a7419dfeece53f83af_c",level:0},(function(e){t.text=JSON.stringify(e),null!=e.errMsg&&uni.showToast({title:e.errMsg,icon:"none"})}))},onPlayError:function(t){null!=t.detail.errEvent&&uni.showToast({title:"playErrorEvent - "+t.detail.errEvent,icon:"none"})},positionChange:function(t){this.skin.timeUpdate(t.detail.currentPosition)},onPlayStatus:function(t){this.skin,this.vodPlayer;var e=t.detail.playbackState,n=t.detail.preparedToPlay;null!=e?this.skin.changePlayStatus("start"===e):null!=n&&(this.updateDuration(),this.updateLevels())},updateDuration:function(){var t=this,e=this.vodPlayer;e&&e.getDuration(null,(function(e){t.skin.updateDuration(e.duration)}))},updateLevels:function(){var t=this,e=this.vodPlayer;e&&(e.getLevelNum(null,(function(e){t.skin.updateLevels(e.levelNum)})),e.getCurrentLevel(null,(function(e){t.skin.updateCurrentLevel(e.currentLevel)})))},onPlayBtnClick:function(t){var e=this.vodPlayer;e&&(t?e.start():e.pause())},onHdBtnClick:function(t){var e=this.vodPlayer;e&&e.changeLevel({level:t})},onRateBtnClick:function(t){var e=this.vodPlayer;e&&e.setSpeed({speed:t})},onFullBtnClick:function(t){plus.screen.unlockOrientation(),t?plus.screen.lockOrientation("landscape-primary"):plus.screen.lockOrientation("portrait-primary"),this.isFull=t},onToSeek:function(t){var e=this.vodPlayer;e&&e.seekTo({seconds:t})},onVolumeChanged:function(t){var e=this,n=this.vodPlayer,o=this.skin;n&&n.getVolume(null,(function(i){var r=i.volume+t,l=e.limit(r,0,1);n.setVolume({volume:l}),o.updateVolumeValue(l)}))},onScreenShot:function(){var e=this.vodPlayer;e&&e.snapshot(null,(function(e){null!=e.errMsg&&t("log",e.errMsg," at pages/sample/ext-player.nvue:183")}))},limit:function(t,e,n){return t<e?e:t>n?n:t}}};e.default=l}).call(this,n(10).default)},function(t,e,n){"use strict";n.r(e);var o=n(18),i=n.n(o);for(var r in o)"default"!==r&&function(t){n.d(e,t,(function(){return o[t]}))}(r);e.default=i.a},function(t,e,n){"use strict";Object.defineProperty(e,"__esModule",{value:!0}),e.default=void 0;var o=l(n(53)),i=l(n(54)),r=l(n(55));function l(t){return t&&t.__esModule?t:{default:t}}var s="https://play1.polyv.net/player2/demo/uniapp/pause-left-btn.png",a="https://play1.polyv.net/player2/demo/uniapp/play-left-btn.png",u="https://play1.polyv.net/player2/demo/uniapp/fullscreen-btn.png",p="https://play1.polyv.net/player2/demo/uniapp/normalscreen-btn.png",c="https://play1.polyv.net/player2/demo/uniapp/bottombar.png",f="https://play1.polyv.net/player2/demo/uniapp/light.png",h="https://play1.polyv.net/player2/demo/uniapp/volume.png",d="https://play1.polyv.net/player2/demo/uniapp/mute.png",v="https://play1.polyv.net/player2/demo/uniapp/screenShot.png",_={components:{Gesture:o.default,Light:i.default,Volume:r.default},data:function(){return{showBar:!0,showBarTime:10,playStatus:!0,playBtnLink:s,fullStatus:!1,fullBtnLink:u,bottomBar:c,timeShowBlock:null,currentTime:null,currentTimeText:"00:00",duration:null,durationText:null,precent:0,progressPrecent:0,progressLeftOverPrecent:100,isDraging:!1,selects:[],selectStatus:!1,types:{LEVEL:"level",SPEED:"speed"},type:null,levels:[["\u81ea\u52a8",0],["\u6d41\u7545",1],["\u9ad8\u6e05",2],["\u8d85\u6e05",3]],level:0,selectedHdAuto:!1,speeds:[["0.5x",.5],["1x",1],["1.5x",1.5],["2x",2]],speed:1,lightImg:f,lightPrecent:0,volumeImg:h,volumeMuteImg:d,volumeValue:.5,screenShotImg:v,screenShotY:"200rpx"}},watch:{type:function(){this.selects=this["".concat(this.type,"s")]}},computed:{currentLevelText:function(){return this.levels[this.level][0]},currentSpeedText:function(){return this.speeds[this.speed][0]},currentOptionIndex:function(){return this.type===this.types.LEVEL?this.level:this.speed}},mounted:function(){this.countHoleWidth(),this.barHide()},methods:{countHoleWidth:function(){var t=this.fullStatus,e=plus.display.resolutionHeight,n=plus.display.resolutionWidth;this.holeWidth=t?e>n?e:n:n<e?n:e},changePlayStatus:function(t){var e=!this.playStatus;void 0!==t&&(e=t),this.playStatus=e,this.playBtnLink=e?s:a},handlePlay:function(){this.playStatus;this.changePlayStatus(),this.$emit("onPlayBtnClick",this.playStatus)},changeFullStatus:function(){var t=!this.fullStatus;this.fullStatus=t,this.fullBtnLink=t?p:u},handleFull:function(){var t=this.fullStatus;this.changeFullStatus(),this.$emit("onFullBtnClick",this.fullStatus),this.countHoleWidth(),this.screenShotY=t?"200rpx":"300rpx"},handleBtn:function(t){this.selectStatus;this.type=t,this.selectStatus=!this.selectStatus},selectOption:function(t){var e=this.types,n=this.type,o=this.speeds;switch(this[n]=t,this.selectStatus=!1,n){case e.LEVEL:this.selectedHdAuto=0===t,this.$emit("onHdBtnClick",t);break;case e.SPEED:this.$emit("onRateBtnClick",o[t][1])}},handleMask:function(){var t=this.selectStatus,e=this.showBar;t?this.selectStatus=!1:e?this.showBar=!1:(this.showBar=!0,this.barHide())},timeUpdate:function(t){this.currentTime=t,this.currentTimeText=this.timeFormat(t),this.updateProgress()},updateDuration:function(t){this.duration=t,this.timeShowBlock=t>=3600?2:1,this.durationText=this.timeFormat(t)},updateProgress:function(t){var e,n=this,o=this.currentTime,i=this.duration,r=(this.finalPrecent,this.isDraging),l=function(t){n.progressPrecent=parseInt(100*t),n.progressLeftOverPrecent=100-n.progressPrecent};if(t)l(e=this.limit(t,0,1));else{if(!i||r)return;e=o/i,this.precent=e,l(e)}},handleTouch:function(t,e){switch(t){case"start":this.initTouchPageX=2*e.touches[0].pageX,this.barShow();break;case"move":this.isDraging=!0;var n=2*e.touches[0].pageX,o=this.getChangedX(n,this.initTouchPageX);this.calcPrecentChange(o);break;case"end":this.isDraging&&(this.toSeek(this.finalPrecent),this.isDraging=!1)}},calcPrecentChange:function(t){var e;e=this.precent+t/this.holeWidth,e=this.limit(e,0,1),this.updateProgress(e),this.finalPrecent=e},getChangedX:function(t,e){return t-e},touchstart:function(t){this.handleTouch("start",t)},touchmove:function(t){this.handleTouch("move",t)},touchend:function(t){this.handleTouch("end",t)},toSeek:function(t){var e=parseInt(t*this.duration);isNaN(e)||this.$emit("onToSeek",e)},handleSeekTo:function(t){isNaN(t)||this.$emit("onToSeek",t)},updateLevels:function(t){if(t){var e=t+1;this.levels=this.levels.slice(0,e)}},updateCurrentLevel:function(t){this.selectedHdAuto||(this.level=t)},barShow:function(){this.clock&&(clearTimeout(this.clock),this.clock=null),this.showBar=!0},barHide:function(t){},handleGEvent:function(t){var e=this;switch(t.type){case"SEEK_TIME_UPDATE":break;case"LEFT_UP":uni.getScreenBrightness({success:function(n){e.setBrightness(n.value,t.position,1)}});break;case"LEFT_DOWN":uni.getScreenBrightness({success:function(n){e.setBrightness(n.value,t.position,-1)}});break;case"RIGHT_UP":this.volumeChanged(t.position,1);break;case"RIGHT_DOWN":this.volumeChanged(t.position,-1)}},setBrightness:function(t,e,n){var o=t+(e=Math.abs(e/6)/100*n);o=this.limit(o,0,1),this.lightPrecent=parseInt(100*o),uni.setScreenBrightness({value:o})},volumeChanged:function(t,e){t=Math.abs(t/10)/100*e,this.$emit("onVolumeChanged",t)},updateVolumeValue:function(t){this.volumeValue=t},timeFormat:function(t){var e=this.timeShowBlock,n=Math.floor(t/3600)<10?"0"+Math.floor(t/3600):Math.floor(t/3600),o=Math.floor(t/60%60)<10?"0"+Math.floor(t/60%60):Math.floor(t/60%60),i=Math.floor(t%60)<10?"0"+Math.floor(t%60):Math.floor(t%60);return 2===e?n+":"+o+":"+i:o+":"+i},limit:function(t,e,n){return t<e?e:t>n?n:t}}};e.default=_},function(t,e,n){"use strict";n.r(e);var o=n(20),i=n.n(o);for(var r in o)"default"!==r&&function(t){n.d(e,t,(function(){return o[t]}))}(r);e.default=i.a},function(t,e,n){"use strict";Object.defineProperty(e,"__esModule",{value:!0}),e.default=void 0;var o={props:{holeWidth:Number,duration:Number,currentTime:Number},computed:{halfWidth:function(){return parseInt(this.holeWidth/2)}},data:function(){return{downLeft:!1,swipeDir:null}},mounted:function(){this.addHandler()},methods:{addHandler:function(){var t=this,e=-1,n=function(n){var o=t.holeWidth,i=t.duration,r=t.currentTime,l=Math.abs(n)/o,s=r||0,a=parseInt(Math.abs(l*i));return n<0&&(a*=-1),e=s+a,e=t.limit(e,0,i)};this.addGesture((function(o,i){switch(o){case-1:t.$emit("onGestureEvent",{type:t.downLeft?"LEFT_DOWN":"RIGHT_DOWN",position:i});break;case-2:t.$emit("onGestureEvent",{type:t.downLeft?"LEFT_UP":"RIGHT_UP",position:i});break;case 0:case 1:t.swipeDir=o,n(i),t.$emit("onGestureEvent",{type:"SEEK_TIME_UPDATE",finalTime:e});break;case 3:t.swipeDir>-1&&(t.$emit("onGestureEvent",{type:t.swipeDir?"SWIPE_RIGHT":"SWIPE_LEFT"}),t.swipeDir=-1),e>-1&&(t.$emit("onGestureSeekTo",e),e=-1);break;case 4:break;case 5:t.handleClick()}}))},addGesture:function(t){var e,n,o,i,r,l,s,a,u,p,c=this,f=(this.options,!0),h=function(e){t&&"function"==typeof t&&t(e,s)},d=function(){(r>50||r<-50)&&(s=r,a="X",f=!1),r>50?h(1):r<-50&&h(0)},v=function(){(l>20||l<-20)&&(s=l,a="Y",f=!1),l>20?h(-1):l<-20&&h(-2)};this.handleTouch=function(t,s){switch(t){case"start":e=s.changedTouches[0].pageX,n=s.changedTouches[0].pageY,u=Date.now(),a="",f=!0,c.downLeft=e<c.halfWidth;break;case"move":o=s.changedTouches[0].pageX,i=s.changedTouches[0].pageY,r=o-e,l=i-n,a?"X"===a?d():v():(d(),v());break;case"end":f?p&&Date.now()-p<=300?h(4):Date.now()-u<1e3?h(5):h(6):h(3),p=Date.now(),f=!0}}},handleClick:function(){this.$emit("onGestureClick")},touchstart:function(t){this.handleTouch("start",t)},touchmove:function(t){this.handleTouch("move",t)},touchend:function(t){this.handleTouch("end",t)},limit:function(t,e,n){return t<e?e:t>n?n:t}}};e.default=o},function(t,e){t.exports={"plv-player-gesture":{flex:1,flexDirection:"row"},"plv-player-gesture__left":{flex:5},"plv-player-gesture__right":{flex:5}}},function(t,e,n){"use strict";n.r(e);var o=n(23),i=n.n(o);for(var r in o)"default"!==r&&function(t){n.d(e,t,(function(){return o[t]}))}(r);e.default=i.a},function(t,e,n){"use strict";Object.defineProperty(e,"__esModule",{value:!0}),e.default=void 0;var o={props:{imgUrl:{type:"string",required:!0},precent:{type:"Number",default:100,required:!0}},watch:{precent:function(t){this.isShow||(this.isShow=!0),this.startClock()}},data:function(){return{isShow:!1}},methods:{startClock:function(){var t=this;this.clearClock(),this.clock=setTimeout((function(){t.isShow=!1}),1500)},clearClock:function(){this.clock&&clearTimeout(this.clock),this.clock=null}}};e.default=o},function(t,e){t.exports={"plv-player-icon":{alignItems:"center",justifyContent:"center"},"plv-player-icon__img":{width:"80rpx",height:"80rpx"},"plv-player-icon__text":{color:"#FFFFFF",textAlign:"center"}}},function(t,e,n){"use strict";n.r(e);var o=n(26),i=n.n(o);for(var r in o)"default"!==r&&function(t){n.d(e,t,(function(){return o[t]}))}(r);e.default=i.a},function(t,e,n){"use strict";Object.defineProperty(e,"__esModule",{value:!0}),e.default=void 0;var o={props:{imgUrl:{type:"string",required:!0},muteImgUrl:{type:"string",required:!0},value:{type:"Number",default:.5,required:!0}},watch:{value:function(t){this.isShow||(this.isShow=!0),this.startClock()}},computed:{valueLeft:function(){return 1-this.value}},data:function(){return{isShow:!1}},methods:{startClock:function(){var t=this;this.clearClock(),this.clock=setTimeout((function(){t.isShow=!1}),1500)},clearClock:function(){this.clock&&clearTimeout(this.clock),this.clock=null}}};e.default=o},function(t,e){t.exports={"plv-player-volume-wrap":{flexDirection:"row",alignItems:"center",justifyContent:"center"},"plv-player-volume__img":{width:"40rpx",height:"40rpx",marginRight:"10rpx"},"plv-player-volume__progress":{width:"260rpx",height:"8rpx",flexDirection:"row",backgroundColor:"#09BB07"},"plv-player-volume__progress__played":{backgroundColor:"#007AFF"},"plv-player-volume__progress_surplus":{backgroundColor:"#FFFFFF"}}},function(t,e){t.exports={"plv-player-mask":{position:"absolute",left:0,right:0,top:0,bottom:"120rpx"},"plv-player-bar__bg":{width:"1624rpx",height:"120rpx"},"plv-player-bar":{position:"absolute",left:0,right:0,height:"120rpx",bottom:0},"plv-player-bar__box":{position:"absolute",left:0,right:0,height:"120rpx",bottom:0,flexDirection:"row"},"plv-player-mr-left":{flex:10},"plv-player-mr-right":{flex:10},"plv-player-middle":{flex:80},"plv-player-progress":{flex:40},"plv-player-progress__play__wrap":{flexDirection:"row",flex:1},"plv-player-progress__wrap__played":{top:"20rpx",height:"8rpx",backgroundColor:"#0A98D5"},"plv-player-progress__wrap__surplus":{top:"20rpx",height:"8rpx",backgroundColor:"#FFFFFF"},"plv-player-progress__dot__wrap":{position:"absolute",top:0,left:0,right:0,bottom:0,zIndex:1},"plv-player-progress__dot__box":{flex:1,flexDirection:"row"},"plv-player-progress__dot__played":{flex:20},"plv-player-progress__dot__surplus":{flex:80},"plv-player-progress__mask":{position:"absolute",top:0,right:0,left:0,bottom:0,borderRadius:"4rpx",zIndex:2},"plv-player-progress__dot":{position:"absolute",width:"10rpx",height:"30rpx",top:"8rpx",right:0,borderRadius:"4rpx",backgroundColor:"#FFFFFF"},"plv-player-bar-bottom":{flexDirection:"row",flex:60},"plv-btn":{position:"relative",width:"64rpx",height:"64rpx",top:"8rpx",bottom:0,marginRight:"10rpx"},"plv-player-full-btn":{position:"absolute",right:0},"plv-player-hd-btn":{position:"absolute",right:"64rpx"},"plv-player-rate-btn":{position:"absolute",right:"128rpx"},"plv-player-time":{position:"relative",top:"8rpx",flexDirection:"row"},"plv-player-select":{position:"absolute",width:"200rpx",right:0,top:0,bottom:0,zIndex:1},"plv-player-select__bg":{position:"absolute",top:0,bottom:0,left:0,right:0,backgroundColor:"#0A98D5",opacity:.5},"plv-player-select__option":{position:"absolute",top:0,bottom:0,left:0,right:0,justifyContent:"center",alignItems:"center"},"plv-player-btn__text":{color:"#FFFFFF",fontSize:"28rpx",lineHeight:"64rpx"},"select-option__text":{color:"#FFFFFF",fontSize:"28rpx",lineHeight:"20rpx",textAlign:"center"},active:{color:"#0A98D5"},"plv-player-light":{flex:1,alignItems:"center"},"plv-player-volume":{position:"absolute",top:"50rpx",left:0,right:0,height:"80rpx"},"plv-player-screenshot":{position:"absolute",marginLeft:"80rpx"},"plv-player-screenshot__btn":{width:"80rpx",height:"80rpx"}}},function(t,e){t.exports={wrap:{flex:1},title:{height:"140rpx"},player:{height:"400rpx"},"player-full":{flex:1},"vod-player":{flex:1},"skin-control":{position:"absolute",top:0,left:0,right:0,bottom:0,zIndex:1},hide:{height:0}}},,,,,,,,,,,function(t,e,n){"use strict";n.d(e,"b",(function(){return o})),n.d(e,"c",(function(){return i})),n.d(e,"a",(function(){}));var o=function(){var t=this,e=t.$createElement,n=t._self._c||e;return n("scroll-view",{staticStyle:{flexDirection:"column"},attrs:{scrollY:!0,showScrollbar:!0,enableBackToTop:!0,bubble:"true"}},[n("view",{staticClass:["wrap"]},[n("head",{class:{title:!0,hide:!0===t.isFull},attrs:{title:t.title}}),n("view",{class:t.isFull?"player-full":"player"},[n("plv-player",{ref:"vod",staticClass:["vod-player"],attrs:{seekType:"0",autoPlay:"true",disableScreenCAP:"false",rememberLastPosition:"false"},on:{onPlayStatus:t.onPlayStatus,onPlayError:t.onPlayError,positionChange:t.positionChange}}),n("skin",{ref:"skin",staticClass:["skin-control"],attrs:{defaultVolume:t.defaultVolume},on:{onPlayBtnClick:t.onPlayBtnClick,onToSeek:t.onToSeek,onFullBtnClick:t.onFullBtnClick,onHdBtnClick:t.onHdBtnClick,onRateBtnClick:t.onRateBtnClick,onVolumeChanged:t.onVolumeChanged,onScreenShot:t.onScreenShot}})],1)],1)])},i=[]},function(t,e,n){"use strict";n.d(e,"b",(function(){return o})),n.d(e,"c",(function(){return i})),n.d(e,"a",(function(){}));var o=function(){var t=this,e=t.$createElement,n=t._self._c||e;return n("view",{staticClass:["skin-wrap"]},[n("gesture",{staticClass:["plv-player-mask"],attrs:{holeWidth:t.holeWidth,duration:t.duration,currentTime:t.currentTime},on:{onGestureClick:t.handleMask,onGestureSeekTo:t.handleSeekTo,onGestureEvent:t.handleGEvent}}),n("light",{staticClass:["plv-player-light"],attrs:{imgUrl:t.lightImg,precent:t.lightPrecent}}),n("volume",{staticClass:["plv-player-volume"],attrs:{imgUrl:t.volumeImg,muteImgUrl:t.volumeMuteImg,value:t.volumeValue}}),!t.selectStatus&&t.showBar?n("view",{staticClass:["plv-player-bar"]},[n("u-image",{staticClass:["plv-player-bar__bg"],attrs:{src:t.bottomBar}}),n("view",{staticClass:["plv-player-bar__box"]},[n("view",{staticClass:["plv-player-mr-left"]}),n("view",{staticClass:["plv-player-middle"]},[n("view",{staticClass:["plv-player-progress"]},[n("view",{staticClass:["plv-player-progress__play__wrap"]},[n("view",{staticClass:["plv-player-progress__wrap__played"],style:"flex:"+t.progressPrecent}),n("view",{staticClass:["plv-player-progress__wrap__surplus"],style:"flex:"+t.progressLeftOverPrecent})]),n("view",{staticClass:["plv-player-progress__dot__wrap"]},[n("view",{staticClass:["plv-player-progress__dot__box"]},[n("view",{staticClass:["plv-player-progress__dot__played"],style:"flex:"+t.progressPrecent},[n("view",{staticClass:["plv-player-progress__dot"]})]),n("view",{staticClass:["plv-player-progress__dot__surplus"],style:"flex:"+t.progressLeftOverPrecent})])]),n("view",{staticClass:["plv-player-progress__mask"],on:{touchstart:t.touchstart,touchmove:t.touchmove,touchend:t.touchend}})]),n("view",{staticClass:["plv-player-bar-bottom"]},[n("u-image",{staticClass:["plv-btn","plv-player-play-btn"],attrs:{src:t.playBtnLink},on:{click:t.handlePlay}}),n("view",{staticClass:["plv-player-time"]},[n("u-text",{staticClass:["plv-player-btn__text"]},[t._v(t._s(t.currentTimeText))]),n("u-text",{staticClass:["plv-player-btn__text"]},[t._v(" / ")]),n("u-text",{staticClass:["plv-player-btn__text"]},[t._v(t._s(t.durationText))])]),n("u-image",{staticClass:["plv-btn","plv-player-full-btn"],attrs:{src:t.fullBtnLink},on:{click:t.handleFull}}),n("u-text",{staticClass:["plv-btn","plv-player-hd-btn","plv-player-btn__text"],on:{click:function(e){t.handleBtn(t.types.LEVEL)}}},[t._v(t._s(t.currentLevelText))]),n("u-text",{staticClass:["plv-btn","plv-player-rate-btn","plv-player-btn__text"],on:{click:function(e){t.handleBtn(t.types.SPEED)}}},[t._v(t._s(t.currentSpeedText))])],1)]),n("view",{staticClass:["plv-player-mr-right"]})])],1):t._e(),t.selectStatus?n("view",{staticClass:["plv-player-select"],on:{click:t.handleSelectClick}},[n("view",{staticClass:["plv-player-select__bg"]}),n("view",{staticClass:["plv-player-select__option"]},t._l(t.selects,(function(e,o){return n("u-text",{key:o,class:{"select-option__text":!0,active:o===t.currentOptionIndex},on:{click:function(e){t.selectOption(o)}}},[t._v("\n\t\t\t\t"+t._s(e[0])+"\n\t\t\t")])})),0)]):t._e(),!t.selectStatus&&t.showBar?n("view",{staticClass:["plv-player-screenshot"],style:"bottom:"+t.screenShotY},[n("u-image",{staticClass:["plv-player-screenshot__btn"],attrs:{src:t.screenShotImg},on:{click:function(e){t.$emit("onScreenShot")}}})],1):t._e()],1)},i=[]},function(t,e,n){"use strict";n.d(e,"b",(function(){return o})),n.d(e,"c",(function(){return i})),n.d(e,"a",(function(){}));var o=function(){var t=this.$createElement,e=this._self._c||t;return this.isShow?e("view",{staticClass:["plv-player-volume-wrap"]},[e("u-image",{staticClass:["plv-player-volume__img"],attrs:{src:0===this.value?this.muteImgUrl:this.imgUrl}}),e("view",{staticClass:["plv-player-volume__progress"]},[e("view",{staticClass:["plv-player-volume__progress__played"],style:"flex:"+this.value}),e("view",{staticClass:["plv-player-volume__progress_surplus"],style:"flex:"+this.valueLeft})])],1):this._e()},i=[]},function(t,e,n){"use strict";n.d(e,"b",(function(){return o})),n.d(e,"c",(function(){return i})),n.d(e,"a",(function(){}));var o=function(){var t=this.$createElement,e=this._self._c||t;return this.isShow?e("view",{staticClass:["plv-player-icon"]},[e("u-image",{staticClass:["plv-player-icon__img"],attrs:{src:this.imgUrl}}),e("u-text",{staticClass:["plv-player-icon__text"]},[this._v(this._s(this.precent+"%"))])],1):this._e()},i=[]},function(t,e,n){"use strict";n.d(e,"b",(function(){return o})),n.d(e,"c",(function(){return i})),n.d(e,"a",(function(){}));var o=function(){var t=this.$createElement;return(this._self._c||t)("view",{staticClass:["plv-player-gesture"],on:{touchstart:this.touchstart,touchmove:this.touchmove,touchend:this.touchend}})},i=[]},function(t,e,n){"use strict";n.r(e);var o=n(21),i=n.n(o);for(var r in o)"default"!==r&&function(t){n.d(e,t,(function(){return o[t]}))}(r);e.default=i.a},function(t,e,n){"use strict";n.r(e);var o=n(24),i=n.n(o);for(var r in o)"default"!==r&&function(t){n.d(e,t,(function(){return o[t]}))}(r);e.default=i.a},function(t,e,n){"use strict";n.r(e);var o=n(27),i=n.n(o);for(var r in o)"default"!==r&&function(t){n.d(e,t,(function(){return o[t]}))}(r);e.default=i.a},function(t,e,n){"use strict";n.r(e);var o=n(28),i=n.n(o);for(var r in o)"default"!==r&&function(t){n.d(e,t,(function(){return o[t]}))}(r);e.default=i.a},function(t,e,n){"use strict";n.r(e);var o=n(29),i=n.n(o);for(var r in o)"default"!==r&&function(t){n.d(e,t,(function(){return o[t]}))}(r);e.default=i.a},,function(t,e,n){"use strict";n.r(e);n(7);var o=n(11);"undefined"==typeof Promise||Promise.prototype.finally||(Promise.prototype.finally=function(t){var e=this.constructor;return this.then((function(n){return e.resolve(t()).then((function(){return n}))}),(function(n){return e.resolve(t()).then((function(){throw n}))}))}),o.default.mpType="page",o.default.route="pages/sample/ext-player",o.default.el="#root",new Vue(o.default)},function(t,e,n){"use strict";n.r(e);var o=n(41),i=n(17);for(var r in i)"default"!==r&&function(t){n.d(e,t,(function(){return i[t]}))}(r);var l=n(0);var s=Object(l.a)(i.default,o.b,o.c,!1,null,null,"b7ed8794",!1,o.a,void 0);(function(t){this.options.style||(this.options.style={}),Vue.prototype.__merge_style&&Vue.prototype.__$appStyle__&&Vue.prototype.__merge_style(Vue.prototype.__$appStyle__,this.options.style),Vue.prototype.__merge_style?Vue.prototype.__merge_style(n(48).default,this.options.style):Object.assign(this.options.style,n(48).default)}).call(s),e.default=s.exports},function(t,e,n){"use strict";n.r(e);var o=n(44),i=n(19);for(var r in i)"default"!==r&&function(t){n.d(e,t,(function(){return i[t]}))}(r);var l=n(0);var s=Object(l.a)(i.default,o.b,o.c,!1,null,null,"88b386a0",!1,o.a,void 0);(function(t){this.options.style||(this.options.style={}),Vue.prototype.__merge_style&&Vue.prototype.__$appStyle__&&Vue.prototype.__merge_style(Vue.prototype.__$appStyle__,this.options.style),Vue.prototype.__merge_style?Vue.prototype.__merge_style(n(45).default,this.options.style):Object.assign(this.options.style,n(45).default)}).call(s),e.default=s.exports},function(t,e,n){"use strict";n.r(e);var o=n(43),i=n(22);for(var r in i)"default"!==r&&function(t){n.d(e,t,(function(){return i[t]}))}(r);var l=n(0);var s=Object(l.a)(i.default,o.b,o.c,!1,null,null,"6d5555c3",!1,o.a,void 0);(function(t){this.options.style||(this.options.style={}),Vue.prototype.__merge_style&&Vue.prototype.__$appStyle__&&Vue.prototype.__merge_style(Vue.prototype.__$appStyle__,this.options.style),Vue.prototype.__merge_style?Vue.prototype.__merge_style(n(46).default,this.options.style):Object.assign(this.options.style,n(46).default)}).call(s),e.default=s.exports},function(t,e,n){"use strict";n.r(e);var o=n(42),i=n(25);for(var r in i)"default"!==r&&function(t){n.d(e,t,(function(){return i[t]}))}(r);var l=n(0);var s=Object(l.a)(i.default,o.b,o.c,!1,null,null,"4870350e",!1,o.a,void 0);(function(t){this.options.style||(this.options.style={}),Vue.prototype.__merge_style&&Vue.prototype.__$appStyle__&&Vue.prototype.__merge_style(Vue.prototype.__$appStyle__,this.options.style),Vue.prototype.__merge_style?Vue.prototype.__merge_style(n(47).default,this.options.style):Object.assign(this.options.style,n(47).default)}).call(s),e.default=s.exports}]);