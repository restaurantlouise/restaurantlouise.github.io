"use strict";var precacheConfig=[["/index.html","58f284b9612085d507da909dd6aa60ac"],["/static/css/main.d56c368b.css","97bed22c8373d7caa09be408ff6f78c6"],["/static/js/main.7fdb6b26.js","e3a196b36ef9629ce8e076abb0ddafbf"],["/static/media/Tangerine-Bold.ba83db53.ttf","ba83db53ea0a5abd5eaea8595793c9df"],["/static/media/Tangerine-Regular.13dd711b.ttf","13dd711b61d355fd1609732d1f22249f"],["/static/media/asperges.75560c54.jpg","75560c543298d5f19d31adbb3f6a018e"],["/static/media/bbq.d9399ca7.jpg","d9399ca76ead77aae9f07ab0684a5f4f"],["/static/media/bg_louise.89e15c9a.jpg","89e15c9a84a0973c49ebf23c9e13482d"],["/static/media/canapes.425b206a.jpg","425b206afa8cabdb5c222267c211734a"],["/static/media/closeup.eeef7096.jpg","eeef709627e4730bcfccf9d5ddd56e75"],["/static/media/cuisine.7b8104e6.jpg","7b8104e61c188100923a72be33359c7b"],["/static/media/dessert.dde3741c.jpg","dde3741c4b4bace13d37b0521f8dbf65"],["/static/media/interieur_bleu.4384081e.jpg","4384081ec17fbbb80aeaea9933daecdf"],["/static/media/interieur_depuis_cuisine.3a29cabf.jpg","3a29cabf22785890f847b5871f0cfb78"],["/static/media/interieur_depuis_rue.d4848016.jpg","d4848016cf310a47e81e929a1980d745"],["/static/media/interieur_table_closeup.c0f9c1ed.jpg","c0f9c1edd4c88ced54de2e7e83a7e943"],["/static/media/julien_bw.d0a4358f.jpg","d0a4358f20a1eb63002f39d52d8fc1d4"],["/static/media/jus_court.32b14a3e.jpg","32b14a3ee64414882daaadcd53e7ec12"],["/static/media/logo_louise.32e75705.png","32e757052a709a255fac253d49d57ff1"],["/static/media/louise_exterieur.641f9d33.jpg","641f9d3333987b0284402824f43169f9"],["/static/media/rhums.3bd88eb6.jpg","3bd88eb689df0f1a14b4eed241507aed"],["/static/media/tablier.50e22111.jpg","50e22111cb7774f7493569bb87b04aa1"],["/static/media/team_bw.502f05b9.jpg","502f05b91df3c981fd46641e7115b98e"]],cacheName="sw-precache-v3-sw-precache-webpack-plugin-"+(self.registration?self.registration.scope:""),ignoreUrlParametersMatching=[/^utm_/],addDirectoryIndex=function(e,t){var a=new URL(e);return"/"===a.pathname.slice(-1)&&(a.pathname+=t),a.toString()},cleanResponse=function(t){return t.redirected?("body"in t?Promise.resolve(t.body):t.blob()).then(function(e){return new Response(e,{headers:t.headers,status:t.status,statusText:t.statusText})}):Promise.resolve(t)},createCacheKey=function(e,t,a,n){var r=new URL(e);return n&&r.pathname.match(n)||(r.search+=(r.search?"&":"")+encodeURIComponent(t)+"="+encodeURIComponent(a)),r.toString()},isPathWhitelisted=function(e,t){if(0===e.length)return!0;var a=new URL(t).pathname;return e.some(function(e){return a.match(e)})},stripIgnoredUrlParameters=function(e,a){var t=new URL(e);return t.hash="",t.search=t.search.slice(1).split("&").map(function(e){return e.split("=")}).filter(function(t){return a.every(function(e){return!e.test(t[0])})}).map(function(e){return e.join("=")}).join("&"),t.toString()},hashParamName="_sw-precache",urlsToCacheKeys=new Map(precacheConfig.map(function(e){var t=e[0],a=e[1],n=new URL(t,self.location),r=createCacheKey(n,hashParamName,a,/\.\w{8}\./);return[n.toString(),r]}));function setOfCachedUrls(e){return e.keys().then(function(e){return e.map(function(e){return e.url})}).then(function(e){return new Set(e)})}self.addEventListener("install",function(e){e.waitUntil(caches.open(cacheName).then(function(n){return setOfCachedUrls(n).then(function(a){return Promise.all(Array.from(urlsToCacheKeys.values()).map(function(t){if(!a.has(t)){var e=new Request(t,{credentials:"same-origin"});return fetch(e).then(function(e){if(!e.ok)throw new Error("Request for "+t+" returned a response with status "+e.status);return cleanResponse(e).then(function(e){return n.put(t,e)})})}}))})}).then(function(){return self.skipWaiting()}))}),self.addEventListener("activate",function(e){var a=new Set(urlsToCacheKeys.values());e.waitUntil(caches.open(cacheName).then(function(t){return t.keys().then(function(e){return Promise.all(e.map(function(e){if(!a.has(e.url))return t.delete(e)}))})}).then(function(){return self.clients.claim()}))}),self.addEventListener("fetch",function(t){if("GET"===t.request.method){var e,a=stripIgnoredUrlParameters(t.request.url,ignoreUrlParametersMatching),n="index.html";(e=urlsToCacheKeys.has(a))||(a=addDirectoryIndex(a,n),e=urlsToCacheKeys.has(a));var r="/index.html";!e&&"navigate"===t.request.mode&&isPathWhitelisted(["^(?!\\/__).*"],t.request.url)&&(a=new URL(r,self.location).toString(),e=urlsToCacheKeys.has(a)),e&&t.respondWith(caches.open(cacheName).then(function(e){return e.match(urlsToCacheKeys.get(a)).then(function(e){if(e)return e;throw Error("The cached response that was expected is missing.")})}).catch(function(e){return console.warn('Couldn\'t serve response for "%s" from cache: %O',t.request.url,e),fetch(t.request)}))}});