# Extraction-of-horizontal-straight-line
提取水平/垂直直线
首先是把输入的图像转换为灰度图（cvtColor()函数），再将灰度图转为二值图（adaptiveThreshold（）函数），再构造结构元素对二值图像进行开操作。（必须背景为黑色）

相关资料：https://www.w3cschool.cn/opencv/opencv-xm1b2cgn.html

该方法可以运用于对验证码的文字提取
