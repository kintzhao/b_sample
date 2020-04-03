 [贝塞尔曲线原理(简单阐述)](https://www.cnblogs.com/hnfxs/p/3148483.html)  <https://www.cnblogs.com/hnfxs/p/3148483.html>

参考: b-spline学习-系数计算及程序实践
https://blog.csdn.net/brightming/article/details/53953926



--------------------------------------------------------------
b-spline的学习网址
对b-spline的介绍网址：
http://www.qiujiawei.com/b-spline-1/

根据上面的网址，找到下面的讲义，这个讲义，内容已经说的很清楚了：
http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/

基本上按照顺序对b-spline的内容读了一次，但其实不够的，最好还是对前因后果都读一下会比较前面。

学习理解
b-spline是一种可以更灵活的表示曲线的数学模型，是对bezier曲线的继承发展。
主要的概念有：knots，control point，degree。

knots
b-spline的定义域是[0,1]之间，而knots是将定义域进行划分的，分成多段子定义域。

degree
degree这个我理解的不深，不好解析。

basic function
b-spline由一系列的basic function组成的，degree的不同，basic function的定义域也不同。

仅仅通过knots，degree就可以计算出basic function，也是系数。
http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/bs-basis.jpg

递归形式如下：


control points
control points影响曲线的shape，basic function，得到定义域内某个值计算出来的point，密集的插值就可以得到一条曲线了。
具体的插值公式为：


所以，当knots确定，degree确定，basic function也就确定了，即系数函数与control point无关。

knots，degree，control point的数量必须满足计算关系：
假设knots的数量为m，degree的值为p，control point的数量为n，则：
m=n+p+1

现有代码
在github上有js版的代码，自己用浏览器控制台执行验证过，确实是可以的，其verify是通过的。
js版b-spline曲线计算代码

动手翻译系数计算函数
虽然已经有了现有代码，可以翻译为c++后直接使用，但为了更好的掌握这个知识，还是自己动手实现一遍系数计算的过程。
参考这里的伪代码：
http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/bspline-curve-coef.html

重要的是对着图去看和理解代码：
http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/bspline-triangle.jpg


测试的数据用的是：
http://www.cs.mtu.edu/~shene/COURSES/cs3621/NOTES/spline/B-spline/bspline-ex-1.html



用opencv图形验证效果(test)
用了基本的计算系数的函数，就可以进行插值了，用opencv的图形来进行操作与显示。

思路
1 设定好degree，以及knots数组
2 创建一个500*500的空白图
3 鼠标在空白图上点击若干个控制点，数量满足要求：m=n+1+p
如果选多了，则只取前面的点
4 选够了控制点后，双击鼠标左键，进行插值，并将结果显示到界面中；
如果没有选够，则提示信息。




