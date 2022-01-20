## 过滤器

* **作用**：进行简单的文本转换，如字母全部大写、货币千位使用逗号分隔等。

* **语法**：

  1. 注册过滤：`Vue.filter(name, callback)`或`new Vue{filters:{}}`，其中第一种是全局，第二种是局部。
  2. 使用过滤器：`{{xxx|过滤器名}}`或`v-bind:属性="xxx|过滤器名"`

* **备注**：

  * 过滤器可以串联，而且可以接收参数：
    * `{{message|filterA|filterB}}` 串联
    * `{{message|filterA('arg1','arg2')}}`接收参数，其中<font color =red>arg1</font>和<font color = red>arg2</font>将分别传给过滤器第二个和第三个参数，因为第一个参数是数据本身
  * 并没有改变原本的数据，而是产生新对应的数据

* **例子**：

  1. 格式化显示当前时间(过滤器的简单使用)

     ```vue
     		<div id="app">
     			{{date|formatDate}}
     		</div>
     		<script type="text/javascript" src="../js/vue.js"></script>
     		<script type="text/javascript">
     			// 在月份、日期、小时等小于10时前面补0
     			var padDate = function(value){
     				return value < 10 ? '0' + value : value;
     			};
     			var app = new Vue({
     				el:'#app',
     				data:{
     					date:new Date()
     				},
     				filters:{
     					formatDate:function(value){ // 这里的value就是需要过滤的数据
     						var date = new Date(value);
     						var year = date.getFullYear();
     						var month = padDate(date.getMonth() + 1);
     						var day = padDate(date.getDate());
     						var hours = padDate(date.getHours());
     						var minutes = padDate(date.getMinutes());
     						var seconds = padDate(date.getSeconds());
     						// 将整理好的数据返回出去
     						return year + '-' + month + '-' + day + ' ' + hours + ':' + minutes + ':' + seconds;
     					}
     				},
     				mounted:function(){
     					var _this = this; // 声明一个变量指向vue实例this，保证作用域一致
     					this.timer = setInterval(function(){
     						_this.date = new Date(); // 修改数据date
     						// console.log(this); 使用_this指向vue实例this的原因就是这里的this指的是window而不再是vue实例
     					}, 1000);
                         /* 	this.timer = setInterval(()=>{
     						this.date = new Date();
     						console.log(this); // 使用箭头函数的话这里的this就是vue实例
     					}) */
     				},
     				beforeDestroy:function(){
     					if (this.timer){
     						clearInterval(this.timer); // 在vue实例销毁前，清除我们的定时器
     					}
     				}
     			})
     		</script>
     ```

  2. 格式化一个固定时间戳(过滤器串联+传参的运用)

     ```vue
     <div id="root">
     			<h2>欢迎来到{{name}}学习</h2>
     			<h2>显示格式化后的时间</h2>
     			<!-- 过滤器实现  本质：就是一个函数-->
     			<h3>现在是：{{time | timeFormater}}</h3>
     			<h3>现在是：{{time | timeFormater("YYYY_MM_DD") | mySlice}}</h3><!-- 串联传递  time先传给timeFormater，然后timeFormater的返回值再传给mySlice，最后展示mySlice的返回值-->
     			<h3 :x="msg|mySlice">河南大学</h3>
     			<!-- <input type="text" v-model="msg|mySlice"/> 会报错，不能用在v-model中 -->
     </div>
     <script type="text/javascript">
     		Vue.config.productionTip = false;
     		// 全局过滤器
     		Vue.filter('mySlice', function(value){
     			return value.slice(0,4);
     		})
     		
     		new Vue({
     			el:"#root",
     			data:{
     				name:"henu",
     				time:1633834532492 ,// 时间戳
     				msg:"开封市龙亭区"
     			},
     			filters:{
     				// 局部过滤器
     				timeFormater(time, str="YYYY-MM-DD HH:mm:ss"){
     					return  dayjs(time).format(str);
     				},
     /* 				mySlice(value){
     					return value.slice(0,4);
     				} */
     			}
     		});
     	
     </script>
     ```

     

## v-if和v-show

* **相同点**：都是控制元素的显示与不显示

* **不同点**：

  * v-show只是简单的CSS属性切换，无论条件真与否，都会被编译。
  * v-if属于真正的条件渲染，它会根据表达式适当地销毁或重建元素及绑定的事件或子组件。若表达式初始值为`false`，则一开始元素/组件并不会被渲染，只有当条件第一次变为真时才开始编译。

* **特点**：

  * v-show：不展示的DOM元素并未被移除，仅仅是在元素上加载了内联样式`display:none`将其隐藏。
  * v-if：不展示的DOM元素直接被移除。

* **适用场景**：

  * v-show适用于频繁切换条件
  * v-if因为切换开销相对较大，更适合条件不经常改变的场景

* **例子**：

  * 使用v-if：

    ```html
    		<div id="app">
    			<template v-if="status == 1">
    				<p>这是一段文本1</p>
    				<p>这是一段文本1</p>
    				<p>这是一段文本1</p>
    				<p>这是一段文本1</p>
    			</template>
    			<p v-else-if="status == 2">这是一段文本2</p>
    			<p v-else>这是一段文本3</p>
    		</div>
    		<script type="text/javascript" src="../js/vue.js"></script>
    		<script type="text/javascript">
    			new Vue({
    				el:'#app',
    				data:{
    					status:1
    				}
    			})
    		</script>
    ```

    * 一次判断多个元素时，可以在`Vue.js`内置的`<template>`使用条件指令，最终渲染的结果不会包括`<template>`标签。
    * v-if、v-else-if、v-else都是<font color = red>条件渲染指令</font>，与if、else、else if类似。

  * 使用v-show：

    ```html
    		<div id="app">
    			<p v-show="status == true">状态为真时显示</p>
    		</div>
    		<script type="text/javascript" src="../js/vue.js"></script>
    		<script type="text/javascript">
    			new Vue({
    				el:'#app',
    				data:{
    					status:true
    				}
    			})
    		</script>
    ```

    * <font color = red>注意</font>：v-show不能在`<template>`上使用

## 列表渲染指令v-for

* **基本用法**：

  将一个数组遍历或枚举一个对象循环显示

  ```html
  		<div id="app">
  			<ul>
  				<li v-for="person in persons">{{person.name}}</li>
  			</ul>
  		</div>
  		<script type="text/javascript" src="../js/vue.js"></script>
  		<script type="text/javascript">
  			new Vue({
  				el:'#app',
  				data:{
  					persons:[
  						{name:'学生'},
  						{name:'教师'},
  						{name:'工人'},
  						{name:'老板'}
  					]
  				}
  			})
  		</script>
  ```

  运行效果：

  - 学生
  - 教师
  - 工人
  - 老板

* **遍历数组时支持一个可选参数作为当前项的索引**：

  ```html
  		<div id="app">
  			<ul>
  				<li v-for="(person, index) in persons">{{index}}——{{person.name}}</li>
  			</ul>
  		</div>
  		<script type="text/javascript" src="../js/vue.js"></script>
  		<script type="text/javascript">
  			new Vue({
  				el:'#app',
  				data:{
  					persons:[
  						{name:'学生'},
  						{name:'教师'},
  						{name:'工人'},
  						{name:'老板'}
  					]
  				}
  			})
  		</script>
  ```

  运行效果：

  - 0——学生
  - 1——教师
  - 2——工人
  - 3——老板

* **支持template**：

  与v-if一样，v-for也可以用在内置标签`<template>`上，将多个元素进行渲染

  ```html
  		<div id="app">
  			<ul>
  				<template v-for="student in students">
  					<li>学号：{{student.id}}</li>
  					<li>姓名：{{student.name}}</li>
  				</template>
  			</ul>
  		</div>
  		<script type="text/javascript" src="../js/vue.js"></script>
  		<script type="text/javascript">
  			new Vue({
  				el:'#app',
  				data:{
  					students:[
  						{id:1, name:'张三'},
  						{id:2, name:'李四'},
  						{id:3, name:'王五'}
  					]
  				}
  			})
  		</script>
  ```

  运行效果：

  - 学号：1
  - 姓名：张三
  - 学号：2
  - 姓名：李四
  - 学号：3
  - 姓名：王五

* **遍历对象的属性**：

  ```html
  		<div id="app">
  			<ul>
  				<li v-for="value in student">{{value}}</li>
  			</ul>
  		</div>
  		<script type="text/javascript" src="../js/vue.js"></script>
  		<script type="text/javascript">
  			new Vue({
  				el:'#app',
  				data:{
  					student:{
  						id:1,
  						name:'张三',
  						address:'河南省新乡市',
  						email:'1234567@qq.com'
  					}
  				}
  			})
  		</script>
  ```

  运行效果：

  - 1
  - 张三
  - 河南省新乡市
  - 1234567@qq.com

* **遍历对象属性时支持两个可选参数**：

  * 键名
  * 索引

  ```html
  <!DOCTYPE html>
  <html>
  	<head>
  		<meta charset="utf-8">
  		<title>v-for使用</title>
  	</head>
  	<body>
  		<div id="app">
  			<ul>
  				<li v-for="(value, key, index) in student">{{index}}——{{key}}——{{value}}</li>
  			</ul>
  		</div>
  		<script type="text/javascript" src="../js/vue.js"></script>
  		<script type="text/javascript">
  			new Vue({
  				el:'#app',
  				data:{
  					student:{
  						id:1,
  						name:'张三',
  						address:'河南省新乡市',
  						email:'1234567@qq.com'
  					}
  				}
  			})
  		</script>
  	</body>
  </html>
  ```

  运行效果：

  - 0——id——1
  - 1——name——张三
  - 2——address——河南省新乡市
  - 3——email——1234567@qq.com

* **支持迭代整数**：

  ```html
  		<div id="app">
  			<ul>
  				<li v-for="i in 10">{{i}}</li>
  			</ul>
  		</div>
  		<script type="text/javascript" src="../js/vue.js"></script>
  		<script type="text/javascript">
  			new Vue({
  				el:'#app'
  			})
  		</script>
  ```

  运行效果：

  - 1
  - 2
  - 3
  - 4
  - 5
  - 6
  - 7
  - 8
  - 9
  - 10

## 数组更新

* **引言**：Vue的核心是数据与视图的双向绑定，当我们修改数组的时候，Vue会检测到数据变化，用v-for遍历数组渲染的视图也会立即更新，但有时候我们修改数组的方式不对，Vue是检测不到的，那么使用何种方法修改数组才能让Vue检测到呢？

* **数组变异的方法**：使用它们改变数组可以触发视图更新。

  * push()： 方法可向数组的末尾添加一个或多个元素，并返回新的长度。 
  * pop()： 方法用于删除并返回数组的最后一个元素。 
  * shift()： 方法用于把数组的第一个元素从其中删除，并返回第一个元素的值。 
  * unshift()：方法可向数组的开头添加一个或更多元素，并返回新的长度。 
  * splice()： 方法向/从数组中添加/删除项目，然后返回被删除的项目。
  * sort()： 方法用于对数组的元素进行排序。 
  * reverse()： 方法用于颠倒数组中元素的顺序。 

* **非变异方法**：使用它们得到的是一个新数组，可以用该新数组来替换旧数组。

  * filter()： 方法创建一个新的数组，新数组中的元素是通过检查指定数组中符合条件的所有元素。 
  * concat()：方法用于连接两个或多个数组。
  * slice()：方法可从已有的数组中返回选定的元素。

  ```html
  		<div id="app">
  			<ul>
  				<li v-for="student in students">{{student.name}}</li>
  			</ul>
  		</div>
  		<script type="text/javascript" src="../js/vue.js"></script>
  		<script type="text/javascript">
  			var app = new Vue({
  				el:'#app',
  				data:{
  					students:[
  						{name:'张三四', id:1},
  						{name:'李四', id:2},
  						{name:'王五', id:3},
  					]
  				}
  			})
  			app.students = app.students.filter(function(item){
  				return item.name.match(/四/);
  			})
  		</script>
  ```

  运行效果：

  - 张三四
  - 李四

* **Vue不能检测到数组变化的一些修改方式**：

  * 通过索引直接设置项，比如app.students[2] = {...}。
  * 修改数组长度，比如app.students.length = 1。

* **通过索引设置项让Vue检测到**(两种方式)：
  1. `app.$set(app.students, 2, {name:'王六', id:3});`
  2. `app.students.splice(2,1,{name:'王六', id:3});`
* **修改数组长度让Vue检测到**：`app.students.splice(1); `    

## 过滤与排序

* **简述**：使用计算属性来返回过滤或排序后的数组

* **例**：

  * 过滤(列出名字带有三字的学生姓名)：

    ```html
    		<div id="app">
    			<ul>
    				<li v-for="student in filterStudents">{{student.name}}</li>
    			</ul>
    		</div>
    		<script type="text/javascript" src="../js/vue.js"></script>
    		<script type="text/javascript">
    			new Vue({
    				el:'#app',
    				data:{
    					students:[
    						{name:'张三', id:1},
    						{name:'李三四', id:2},
    						{name:'王五', id:3}
    					]
    				},
    				computed:{
    					filterStudents:function(){
    						return this.students.filter(function(item){
    							return item.name.match(/三/);
    						})
    					}
    				}
    			})
    		</script>
    ```

  * 排序(将学生姓名按长度从小到大排列展示)

    ```html
    		<div id="app">
    			<ul>
    				<li v-for="student in sortedStudents">{{student.name}}</li>
    			</ul>
    		</div>
    		<script type="text/javascript" src="../js/vue.js"></script>
    		<script type="text/javascript">
    			new Vue({
    				el:'#app',
    				data:{
    					students:[
    						{name:'张三四', id:3},
    						{name:'李五', id:2},
    						{name:'王六七八', id:1}
    					]
    				},
    				computed:{
    					sortedStudents:function(){
    						return this.students.sort(function(a, b){
    							return a.name.length - b.name.length;
    						})
    					}
    				}
    			})
    		</script>
    ```

    * 想要按名字长度从大到小排就将比较条件换为`b.name.length - a.name.length;`


## 事件修饰符

* **Vue中的事件修饰符**：
  1. prevent：阻止默认事件(常用)
  2. stop：阻止事件冒泡(常用)
  3. once：事件只触发一次(常用)
  4. capture：使用事件的捕获模式
  5. self：只有evnet.target是当前操作的元素时才触发事件
  6. passive：事件的默认行为立即执行，无需等待事件回调执行完毕
  
* **使用**：在@绑定的事件后加小圆点“.”，再跟一个后缀来使用修饰符。

* **例子**：

  1. 阻止默认事件：

     ```html
     		<div id="app">
     			<h2>欢迎来到{{name}}</h2>
     			<!-- 阻止默认事件 -->
     			<a href="http://www.baidu.com" @click.prevent="handleClick">点我提示信息</a>
     		</div>
     		<script type="text/javascript" src="../js/vue.js"></script>
     		<script type="text/javascript">
     			new Vue({
     				el:'#app',
     				data:{
     					name:'河南大学'
     				},
     				methods:{
     					handleClick(e){
     						// e.preventDefault();在vue当中不需要用这个，用事件修饰符prevent，阻止a标签的默认行为(跳转)
     						alert("欢迎到来!")
     					}
     				}
     			})
     		</script>
     ```

  2. 阻止事件冒泡：

     * 事件冒泡举例：点击一个按钮时，由于它的外部容器div也有点击回调，浏览器执行了两次点击回调。
     * 阻止事件冒泡的目的：在点击按钮的时候，我们只触发该按钮的点击回调，而不触发其外部容器div的点击回调。

     ```html
     <!DOCTYPE html>
     <html>
     	<head>
     		<meta charset="utf-8">
     		<title>事件修饰符</title>
     		<style type="text/css">
     			*{
     				margin-top: 20px;
     			}
     			.demo1{
     				width: 100px;
     				height: 100px;
     				background-color: red;
     			}
     		</style>
     	</head>
     	<body>
     		<div id="app">
     			<h2>欢迎来到{{name}}</h2>
     			<!-- 阻止冒泡事件 -->
     			<div class="demo1" @click="showInfo">
     				<button @click.stop="showInfo">点我提示信息</button>
     			</div>
     		</div>
     		<script type="text/javascript" src="../js/vue.js"></script>
     		<script type="text/javascript">
     			new Vue({
     				el:'#app',
     				data:{
     					name:'河南大学'
     				},
     				methods:{
     					showInfo(e){
     						// e.stopPropagation();// 使用原生js阻止事件冒泡
     						alert("你好!")
     					}
     				}
     			})
     		</script>
     	</body>
     </html>
     ```

  3. 事件只触发一次：

     ```html
     <div id="app">
     			<h2>欢迎来到{{name}}</h2>
     			<button @click.once="showInfo">事件只触发一次</button>
     		</div>
     		<script type="text/javascript" src="../js/vue.js"></script>
     		<script type="text/javascript">
     			new Vue({
     				el:'#app',
     				data:{
     					name:'河南大学'
     				},
     				methods:{
     					showInfo(e){
     						alert("你好!")
     					}
     				}
     			})
     		</script>
     ```

  4. 使用事件的捕获模式：

     * 捕获跟冒泡是相反的两个过程

     * 何为捕获？

       答：当你点击一个按钮时，其外部容器div也有点击回调，默认按照冒泡的顺序去执行这两个回调，即先执行按钮的点击回调，再执行外部div的点击回调，`捕获`就是与冒泡相反的过程，先执行外部div的点击回调，再执行按钮的点击回调。

     ```html
     <div id="app">
     			<h2>欢迎来到{{name}}</h2>
     			<div class="box1" @click.capture="showMsg(1)">
     				div1
     				<div class="box2" @click="showMsg(2)">
     					div2
     				</div>
     			</div>
     		</div>
     		<script type="text/javascript" src="../js/vue.js"></script>
     		<script type="text/javascript">
     			new Vue({
     				el:'#app',
     				data:{
     					name:'河南大学'
     				},
     				methods:{
     					showMsg(num){
     						window.alert("你好!"+num);
     					}
     				}
     			})
     		</script>
     ```

  5. self的使用：

     * 还是以点击一个按钮为例，当点击该按钮时，由于冒泡，其外部的div点击也被触发，但获取的event.target都是该按钮，这时，给外部div的点击事件添加self修饰符(当event.target不是本元素时，不会执行事件回调)，可以起到与阻止冒泡一样的效果。

     ```html
     <!DOCTYPE html>
     <html>
     	<head>
     		<meta charset="utf-8">
     		<title>事件修饰符</title>
     		<style type="text/css">
     			*{
     				margin-top: 20px;
     			}
     			.demo1{
     				width: 100px;
     				height: 100px;
     				background-color: red;
     			}
     		</style>
     	</head>
     	<body>
     		<div id="app">
     			<h2>欢迎来到{{name}}</h2>
     			<div class="demo1" @click.self="showInfo">
     				<button @click="showInfo">点我提示信息</button>
     			</div>
     		</div>
     		<script type="text/javascript" src="../js/vue.js"></script>
     		<script type="text/javascript">
     			new Vue({
     				el:'#app',
     				data:{
     					name:'河南大学'
     				},
     				methods:{
     					showInfo(event){
     						//console.log(event.target);
     						alert("你好!")
     					}
     				}
     			})
     		</script>
     	</body>
     </html>
     ```

  6. 事件的默认行为立即执行：

     * 无需等待事件回调完毕(浏览器默认是将事件回调执行完毕后才执行事件的默认行为)
     * 并不是所有事件都需要，常用在移动端设备

     ```html
     <!DOCTYPE html>
     <html>
     	<head>
     		<meta charset="utf-8">
     		<title>事件修饰符</title>
     		<style type="text/css">
     			*{
     				margin-top: 20px;
     			}
     			.list{
     				width: 300px;
     				height: 300px;
     				background-color: bisque;
     				overflow: auto;
     			}
     			li{
     				height: 200px;
     			}
     		</style>
     	</head>
     	<body>
     		<div id="app">
     			<h2>欢迎来到{{name}}</h2>
     			<!-- 立即执行事件的默认行为，不用等待事件复杂计算完毕再执行默认行为，但并不是所有事件都需要，scroll滚动条滚动就不需要 -->
     			<ul @wheel.passive="demo" class="list">
     				<li>1</li>
     				<li>2</li>
     				<li>3</li>
     				<li>4</li>
     			</ul>
     		</div>
     		<script type="text/javascript" src="../js/vue.js"></script>
     		<script type="text/javascript">
     			new Vue({
     				el:'#app',
     				data:{
     					name:'河南大学'
     				},
     				methods:{
     					demo(){
     						for(let i = 0; i < 100000; ++i){
     							console.log("#");
     						}
     						console.log("好累啊!");
     					}
     				}
     			})
     		</script>
     	</body>
     </html>
     ```


## v-model

### 用途

用于在表单类元素(单选、多选、下拉选择、输入框等)上双向绑定数据。

### 简单使用

* v-model与input输入框的搭配使用：

  ```html
  		<div id="app">
  			<input type="text" v-model="message" placeholder="输入...."/>
  			<p>输入的内容是：{{message}}</p>
  		</div>
  		<script type="text/javascript" src="../js/vue.js">
  		</script>
  		<script type="text/javascript">
  			var app = new Vue({
  				el:'#app',
  				data:{
  					message:''
  				}
  			})
  		</script>
  ```

### 注意

<font  color = red>使用v-model后：</font>

* 表单控件显示的值只依赖所绑定的数据，不再关心初始化时的value属性

* 对于在`<textarea></textarea>`之间插入的值，也不会生效

* 使用v-model时，如果是用中文输入法输入中文，一般在没有选定词组前，也就是拼音阶段，Vue是不会更新数据的，当敲下汉字时才会触发更新。如果希望总是实时更新，可以使用`@input`代替`v-model`

  用法：

  ```html
  		<div id="app">
  			<textarea @input="handleInput" placeholder="输入..."></textarea>
  			<p>输入的内容是：</p>
  			<p style="white-space: pre;">{{text}}</p>
  		</div>
  		<script type="text/javascript" src="../js/vue.js">
  		</script>
  		<script type="text/javascript">
  			var app = new Vue({
  				el:'#app',
  				data:{
  					text:''
  				},
  				methods:{
  					handleInput:function(e){
  						this.text = e.target.value;
  					}
  				}
  			})
  		</script>
  ```

### 单选按钮上使用

单选按钮在单独使用时，不需要`v-model`，直接使用`v-bind`绑定一个布尔类型的值，为真时选中，为否时不选。

例：

```html
		<div id="app">
			<input type="radio" :checked="picked"/>
			<label>单选按钮</label>
		</div>
		<script type="text/javascript" src="../js/vue.js">
		</script>
		<script type="text/javascript">
			var app = new Vue({
				el:'#app',
				data:{
					picked:true
				}
			})
		</script>
```

如果是组合使用来实现互斥选择的效果，就需要`v-model`配合`value`来使用。

例：

```html
		<div id="app">
			<input type="radio" v-model="picked" id="badminton" value="羽毛球" />
			<label for="badminton">羽毛球</label>
			<br/>
			<input type="radio" v-model="picked" id="basketball" value="篮球" />
			<label for="basketball">篮球</label>
			<br/>
			<input type="radio" v-model="picked" id="football" value="足球" />
			<label for="football">足球</label>
			<br/>
			<p>选择的项是：{{picked}}</p>
		</div>
		<script type="text/javascript" src="../js/vue.js">
		</script>
		<script type="text/javascript">
			var app = new Vue({
				el:'#app',
				data:{
					picked:"篮球"
				}
			})
		</script>
```

数据的`picked`值与单选按钮的value值一致时，就会选中该项。

### 复选框上使用

复选框也分单独使用和组合使用，不过用法稍与单选不同。复选框单独使用时，是用`v-model`来绑定一个布尔值。

例：

在勾选时，数据checked的值变为了true，label中渲染的内容也会更新。

```html
		<div id="app">
			<input type="checkbox" v-model="checked" id="checked"/>
			<label for="checked">选择状态：{{checked}}</label>
		</div>
		<script type="text/javascript" src="../js/vue.js">
		</script>
		<script type="text/javascript">
			var app = new Vue({
				el:'#app',
				data:{
					checked:false
				}
			})
		</script>
```

组合使用时，也是`v-model`与`value`一起，多个勾选框都绑定到同一个数组类型的数据，`value`的值在数组当中，就会选中这一项。这一过程也是双向的，在勾选时，`value`的值也会自动`push`到这个数组中。

例：

```html
		<div id="app">
			<input type="checkbox" v-model="checked" id="badminton" value="羽毛球" />
			<label for="badminton">羽毛球</label>
			<br/>
			<input type="checkbox" v-model="checked" id="basketball" value="篮球" />
			<label for="basketball">篮球</label>
			<br/>
			<input type="checkbox" v-model="checked" id="football" value="足球" />
			<label for="football">足球</label>
			<br/>
			<p>选择的项是：{{checked}}</p>
		</div>
		<script type="text/javascript" src="../js/vue.js">
		</script>
		<script type="text/javascript">
			var app = new Vue({
				el:'#app',
				data:{
					checked:['羽毛球', '篮球']
				}
			})
		</script>
```

### 选择列表上使用

选择列表就是下拉选择器，也就是常见的表单控件，同样也分为单选和多选两种。

单选例：

* 备注：`<option>`是备选项，如果含有value属性，v-model会优先匹配value值；如果没有，就会直接匹配`<option>`的text，比如选中第一项时，selected的值是badminton，而不是羽毛球，但选中第二项时，由于没有value属性，selected的值就是篮球。

```html
		<div id="app">
			<select v-model="selected">
				<option value ="badminton">羽毛球</option>
				<option>篮球</option>
				<option>足球</option>
			</select>
		</div>
		<script type="text/javascript" src="../js/vue.js">
		</script>
		<script type="text/javascript">
			var app = new Vue({
				el:'#app',
				data:{
					selected:'篮球'
				}
			})
		</script>
```

多选例：

* 备注：给`<select>`添加属性`multiple`就可以多选了，此时v-model绑定的是一个<font color = red>数组</font>，与复选框用法类似。

```html
		<div id="app">
			<select v-model="selected" <multiple></multiple>>
				<option v-for="item in options" :value="item.value">{{item.text}}</option>
			</select>
		</div>
		<script type="text/javascript" src="../js/vue.js">
		</script>
		<script type="text/javascript">
			var app = new Vue({
				el:'#app',
				data:{
					selected:'basketball',
					options:[
						{text:'篮球', value:'basketball'},
						{text:'羽毛球', value:'badminton'},
						{text:'足球', value:'football'}
					]
				}
			})
		</script>
```

**注**：虽然用选择列表`<select>`可以很简单地完成下拉选择的需求，但在实际业务中由于样式依赖平台和浏览器，无法统一，也不太美观，功能也受限，比如不支持搜索，故并不常用。常见的解决方案是用div模拟一个类似的控件。

### 修饰符

与事件修饰符类似，v-model也有修饰符，用于控制数据同步的时机。

#### .lazy

在输入框中，`v-model默认`是在`input事件`中同步输入框的数据(除了提示中介绍的中文输入 法情况外)，使用修饰符`.lazy`会转变为在`change`事件中同步，示例代码如下：

```html
		<div id="app">
			<input type="text" v-model.lazy="message"/>
			<p>{{message}}</p>
		</div>
		<script type="text/javascript" src="../js/vue.js">
		</script>
		<script type="text/javascript">
			var app = new Vue({
				el:'#app',
				data:{
					message:''
				}
			})
		</script>
```

这时，message并不是实时改变的，而是在失焦或按回车时才更新。

#### .number

使用修饰符`.number`可以将输入转换为`Number类型`，否则虽然你输入的是数字，但它的类型其实是String，比如在数字输入框时会比较有用，示例代码如下：

```html
		<div id="app">
			<input type="number" v-model.number="message"/>
			<p>{{message}}</p>
		</div>
		<script type="text/javascript" src="../js/vue.js">
		</script>
		<script type="text/javascript">
			var app = new Vue({
				el:'#app',
				data:{
					message:''
				}
			})
		</script>
```

#### .trim

修饰符`.trim`可以自动过滤输入的首尾空格，示例代码如下：

```html
		<div id="app">
			<input type="text" v-model.trim="message"/>
			<p>{{message}}</p>
		</div>
		<script type="text/javascript" src="../js/vue.js">
		</script>
		<script type="text/javascript">
			var app = new Vue({
				el:'#app',
				data:{
					message:''
				}
			})
		</script>
```

## 组件

### 简介

* **地位**：组件是Vue.js最核心的功能，也是整个框架设计最精彩的地方
* **何为组件**：没见过的自定义标签就是组件
* **使用条件**：在任何使用Vue的地方都可以直接使用
* **命名**：推荐用小写+减号分隔的形式命名

### 简单使用

**例1**：

```html
		<div id="app">
			<table>
				<tbody is="my-component"></tbody>
			</table>
		</div>
		<script type="text/javascript" src="../js/vue.js">
		</script>
		<script type="text/javascript">
			var Child = {template:'<div>这是一个组件</div>'};
			// Vue.component('my-component', Child); 全局注册
			var app = new Vue({
				el:'#app',
				components:{ // 局部注册
					'my-component':Child
				}
			})
		</script>
```

这个例子是在table中使用组件，其中涉及到两个需要注意的知识点：

1. Vue组件的模板在某些情况下会受到HTML的限制，比如`<table>`内规定只允许是`<tr>`、`<td>`、`<th>`等表格元素，所以在`<table>`中直接使用组件是无效的，这种情况下，就使用我们上述例子中的方法——使用特殊的is属性来挂载组件，最终tbody在渲染的时候，会被替换为组件的内容。常见的限制元素还有`<ul>`、`<ol>`、`<select>`。
2. template的DOM结构必须被一个元素包含，如果直接写成“这是一个组件”，不带"`<div></div>`"是无法渲染的。

**例2**：

知识点：

在组件中像Vue实例一样使用其他选项(如data、computed、methods等)。但在使用data时，和实例稍有区别，data必须是函数，然后将数据return出去。

```html
		<div id="app">
			<table>
				<tbody is="my-component"></tbody>
			</table>
		</div>
		<script type="text/javascript" src="../js/vue.js">
		</script>
		<script type="text/javascript">
			var Child = {template:'<div>{{message}}</div>', data:function(){
					return {
						message:'这是一个组件2'
					}
				}
			};
			// Vue.component('my-component', Child); 全局注册
			var app = new Vue({
				el:'#app',
				components:{ // 局部注册
					'my-component':Child
				}
			})
		</script>
```

### 使用props传递数据

* **简介**：一种父组件向子组件传递数据或参数的方式。

* **使用方法**：在子组件中通过使用选项`props`来声明需要从父级接收的数据，`props`的值可以是两种，一种是字符串数组，一种是对象。

* **props与组件data的区别**：props来自父级，data中的是组件自己的数据，作用域是组件本身，这两数据都可以在模板template及计算属性computed和方法methods中使用。

* **例子**：

  1. props的值为字符串数组：

     ```html
     		<div id="app">
     			<my-component warning-text="提示信息"></my-component>
     		</div>
     		<script type="text/javascript" src="../js/vue.js">
     		</script>
     		<script type="text/javascript">
     			var Child = {template:'<div>{{warningText}}</div>',props:['warningText']};
     			// Vue.component('my-component', Child); 全局注册
     			var app = new Vue({
     				el:'#app',
     				components:{ // 局部注册
     					'my-component':Child
     				}
     			})
     		</script>
     ```

     * <font color = red>注意</font>：
       1. 由于HTML特性不区分大小写，当使用DOM模板时，驼峰命名(camelCase)的props名称要转为短横分隔命名(kebab-case)。在字符串模板中可以忽略这些限制。
       2. 如果要传递的数据并不是直接写死的，可以使用指令v-bind来动态绑定props的值，当父组件的数据变化时，也会传递给子组件。
       3. 如果要直接传递数字、布尔值、数组、对象，而且不使用v-bind，传递的仅是字符串。
       4. 在Vue2.x通过props传递数据是单向的了，也就是父组件数据变化时会传递给子组件，反过来不行。(这里指的数据是指除对象和数组外的一般数据)
       5. 在业务中遇到两种需要修改prop的情况，一种是父组件传递初始值进来，子组件将它作为初始值保存起来，在自己的作用域下可以随意使用和修改(在组件data中声明一个数据，引用父组件的prop)。另一种就是prop作为需要被转变的原始值传入，这种情况使用计算属性就可以了。
       6. 在JavaScript中对象和数组是引用类型，指向同一个内存空间，所以props是对象和数组时，在子组件内改变是会影响父组件的。

  2. props值为对象：

     * 何时用？

       答：当prop需要验证时，就需要对象写法。如果传入数据不符合规则，会在控制台发出警告。

     * 验证的type类型可以是(type也可以是一个自定义的构造器，使用instanceof 检测)：

       * String
       * Number
       * Boolean
       * Object
       * Array
       * Function

     ```javascript
     Vue.component('my-component',{
     	props:{ // 必须是数字类型
     		propA:Number,
             // 必须是数字或字符串类型
             propB:[Number,String],
             // 布尔值，如果没有定义，默认就是true
             propC:{
                 type:Boolean,
                 default:true
             },
             // 数字，而且是必传
             propD:{
                 type:Number,
                 required:true
             },
             // 如果是数组或对象，设置默认值时必须是一个函数来返回
             propE:{
                 type:Array,
                 default:function(){
                     return [];
                 }
             },
             // 自定义一个验证函数
             propF:{
                 validator:function(value){
                     return value > 10;
                 }
             }
     	}
     })
     ```

     

### 使用$emit传递数据

* **简介**：一种子组件向父组件传递数据或参数的方式。

* **使用方法**：子组件通过`$emit()`来触发事件，父组件用`$on()`来监听子组件的事件或直接在子组件的自定义标签上使用`v-on`来监听子组件触发的自定义事件。

* **解除监听**：`$off()`

* **示例**：

  * **描述**：子组件有两个按钮，分别实现+1和-1效果，在改变组件的data的`counter`后，通过`$emit()`再把它传递给父组件，父组件通过`$on()`或`v-on`来监听子组件触发的事件。

  ```html
  		<div id="app">
  			<p>{{total}}</p>
  			<!-- <my-component @increase="handleGetTotal" @decrease="handleGetTotal"></my-component> -->
  			<my-component ref="child"></my-component>
  		</div>
  		<script type="text/javascript" src="../js/vue.js">
  		</script>
  		<script type="text/javascript">
  			Vue.component('my-component', {
  				template:'\
  					<div>\
  						<button @click="handleIncrease">+1</button>\
  						<button @click="handleDecrease">-1</button>\
  					</div>',
  				data:function(){
  					return {
  						count:0
  					}
  				},
  				methods:{
  					handleIncrease:function(){
  						this.count++;
  						this.$emit('increase', this.count);
  					},
  					handleDecrease:function(){
  						this.count--;
  						this.$emit('decrease', this.count);
  					}
  				}
  			})
  			var app = new Vue({
  				el:'#app',
  				data:{
  					total:0
  				},
  				methods:{
  					handleGetTotal:function(total){
  						this.total = total;
  					}
  				},
  				mounted:function(){
  					this.$refs.child.$on('increase', this.handleGetTotal);
  					// this.$refs.child.$once('increase', this.handleGetTotal); 自定义事件只触发一次
  					this.$refs.child.$on('decrease', this.handleGetTotal);
  				}
  			})
  		</script>
  ```

* **补充**：除了用`v-on`在组件上监听自定义事件外，也可以监听DOM事件，这时可以用`.native`修饰符表示监听的是一个原生事件，监听的是该组件的根元素。例：`<my-component v-on:click.native="handleClick"></my-component>`

* **使用v-model**：

  * Vue2.x可以在自定义组件上使用v-model指令
  * 在下面示例中，实现的效果仍是点击按钮+1，不过这次组件`$emit()`的事件名是特殊的input，在使用组件的父级，并没有在`<my-component>`上使用`@input="handler"`，而是直接用`v-model`绑定的一个`数据total`。

  ```html
  		<div id="app">
  			<p>总数：{{total}}</p>
  			<my-component v-model="total" ></my-component>
  		</div>
  		<script type="text/javascript" src="../js/vue.js">
  		</script>
  		<script type="text/javascript">
  			Vue.component('my-component',{
  				template:'<button @click="handleClick">+1</button>',
  				data:function(){
  					return {
  						counter:0
  					}
  				},
  				methods:{
  					handleClick:function(){
  						this.counter++;
  						this.$emit('input', this.counter);
  					}
  				}
  			});
  			var app = new Vue({
  				el:'#app',
  				data:{
  					total:0
  				}
  			})
  		</script>
  ```

  在上例的v-model，相当于下面的操作：

  ```html
  		<div id="app">
  			<p>总数：{{total}}</p>
  			<my-component @input="handleGetTotal" ></my-component>
  		</div>
  		<script type="text/javascript" src="../js/vue.js">
  		</script>
  		<script type="text/javascript">
  			Vue.component('my-component',{
  				template:'<button @click="handleClick">+1</button>',
  				data:function(){
  					return {
  						counter:0
  					}
  				},
  				methods:{
  					handleClick:function(){
  						this.counter++;
  						this.$emit('input', this.counter);
  					}
  				}
  			});
  			var app = new Vue({
  				el:'#app',
  				data:{
  					total:0
  				},
  				methods:{
  					handleGetTotal(total){
  						this.total = total;
  					}
  				}
  			})
  		</script>
  ```

  利用v-model这一特殊用途，还可以创建自定义表单输入组件，进行数据双向绑定，例如：

  ```html
  		<div id="app">
  			<p>总数：{{total}}</p>
  			<my-component v-model="total" ></my-component>
  			<button @click="handleReduce">-1</button>
  		</div>
  		<script type="text/javascript" src="../js/vue.js">
  		</script>
  		<script type="text/javascript">
  			Vue.component('my-component',{
  				props:['value'],
  				template:'<input :value="value" @input="updateValue">',
  				methods:{
  					updateValue:function(event){
  						this.$emit('input', event.target.value);
  					}
  				}
  			});
  			var app = new Vue({
  				el:'#app',
  				data:{
  					total:0
  				},
  				methods:{
  					handleReduce:function(){
  						this.total--;
  					}
  				}
  			})
  		</script>
  ```

  实现上述一个具有双向绑定的v-model组件要满足如下2个要求：

  1. 接收一个value属性
  2. 在有新的value时触发input事件

### 使用中央事件总线bus传递数据

* **简介**：一种适用于<font color = red>任意组件间通信</font>的方式

* **安装**：

  ```javascript
  new Vue({
  	......
  	beforeCreate() {
  		Vue.prototype.$bus = this //安装全局事件总线，$bus就是当前应用的vm
  	},
      ......
  }) 
  ```

* **使用事件总线**：

  1. 接收数据：A组件想接收数据，则在A组件中给$bus绑定自定义事件，事件的<span style="color:red">回调留在A组件自身。</span>

     ```javascript
     methods(){
       demo(data){......}
     }
     ......
     mounted() {
       this.$bus.$on('xxxx',this.demo)
     }
     ```

  2. 提供数据：`this.$bus.$emit('xxxx',数据)`

* **解绑时机**：在`beforeDestroy`钩子中，用`$off`去解绑当前<font color = red>当前组件所用到的</font>事件。

* **示例**：

  ```html
  <div id="app">
  			<component-a></component-a>
  			<br/>
  			<component-b></component-b>
  			<button @click="sendMessage">点我向儿子组件发送数据</button>
  		</div>
  		<script type="text/javascript" src="../js/vue.js">
  		</script>
  		<script type="text/javascript">
  			var app = new Vue({
  				el:'#app',
  				data:{
  					message:'我是根组件的数据'
  				},
  				components:{
  					'component-a':{
  						template:'<div>\
  						这是来自根组件的信息：{{messageRoot}}<br/>\
  						这是来自兄弟组件的信息：{{messageBrother}}\
  						</div>',
  						data:function(){
  							return {
  								messageRoot:'',
  								messageBrother:''
  							}
  						},
  						methods:{
  							getRootMessage:function(message){
  								this.messageRoot = message;
  							},
  							getBrotherMessage:function(message){
  								this.messageBrother = message;
  							}
  						},
  						mounted:function(){
  							// 给bus绑定自定义事件，回调留在自身，说明我想获得数据
  							this.$bus.$on('RootMessage', this.getRootMessage); 
  							this.$bus.$on('BrotherMessage', this.getBrotherMessage);
  						}
  					},
  					'component-b':{
  						template:'<div>\
  							<button @click="sendMessage">点我向兄弟组件发送数据</button>\
  						</div>',
  						data:function(){
  							return {
  								message:'我是兄弟组件的数据'
  							}
  						},
  						methods:{
  							sendMessage(){
  								this.$bus.$emit('BrotherMessage', this.message);
  							}
  						}
  					}
  				},
  				methods:{
  					sendMessage(){
  						this.$bus.$emit('RootMessage', this.message);
  					}
  				},
  				beforeCreate(){
  					Vue.prototype.$bus = this; // 安装中央事件总线bus
  				}
  			})
  		</script>
  ```

  



