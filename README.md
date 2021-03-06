# [Menu]基于逐飞RT1064开源库的菜单架构

*本项目基于逐飞RT1064开源库进行开发*

![IMG_20210824_021746](https://raw.githubusercontent.com/FerostMask/Photos_repository/master/IMG_20210824_155303.jpg)

我是16届智能车双车组的参赛选手，主要负责软件方面的工作。我在准备比赛的过程中发现，参数调整在整个备赛过程中的时间占比非常大，所以一个便于调参、功能丰富的菜单实现非常重要。于是我根据日常调参的需求制作了这套菜单。

## 介绍视频

>   视频链接：[智能车代码开源 | 基于逐飞RT1064开源库制作的菜单]([智能车代码开源 | 基于逐飞RT1064开源库制作的菜单_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV19P4y1p7dr?))

![序列 02.00_00_46_22.Still001.png](https://github.com/FerostMask/Photos_repository/blob/master/%E5%BA%8F%E5%88%97%2002.00_00_46_22.Still001.png?raw=true)

## 菜单主要功能

>   一级菜单
>

![IMG_20210824_163038](https://raw.githubusercontent.com/FerostMask/Photos_repository/master/IMG_20210824_163038.jpg)

一级菜单主要用于选择需要使用的功能，例如修改参数、显示图像等。选中菜单按下确定键即可进入相应二级菜单。

选项选择分为两个维度，一个是行一个是列，通过上下按键可以选择行，左右按键切换当行下的列选项。

选项数量可以通过`menu.h`文件中的ROWS宏定义和`menu.c`中的`menu`数组初始化进行修改，宏定义ROWS修改的是一级菜单的行数，数组初始化内容是对应行菜单的列数。菜单对应的中文名需要在`info`函数中添加，索引对应着行和列。

>   二级菜单 - 参数修改

![IMG_20210824_021735](https://raw.githubusercontent.com/FerostMask/Photos_repository/master/IMG_20210824_165033.jpg)

参数修改二级菜单是本项目的一个重要功能，它主要实现了参数修改、保存功能。

在参数修改菜单下，红框表示你当前选择的参数项，通过上下按键可以在不同参数间进行切换。选中想要修改的参数后，按下确定键即可对参数进行修改。修改参数时，通过上下按键增加或减少参数值，每次修改的数值默认为1，通过左右按键可以切换不同的修改等级*（具体修改等级显示在`参数值`右下角，该功能仅在二级菜单下有效）*

连续使用上按键将索引指向最上方（第一个参数上方）会显示参数保存字样，此时按下确定键会对当前页的参数进行保存，同时显示已保存字样。

参数修改菜单分为短整型`short`和浮点型`float`，需要根据自己的修改需要选择对应的菜单模式。

>   二级菜单 - 按钮切换

![IMG_20210824_155303](https://raw.githubusercontent.com/FerostMask/Photos_repository/master/IMG_20210824_021735.jpg)



按钮切换功能菜单主要用于实现需要启动停止或单次触发的功能，例如显示摄像头采集图像、二值化图像，还原参数等。

在该菜单中你可以通过确定键将对应功能设置为启动或者关闭（这需要你提前在程序中设定好功能和标志位），这些功能在返回一级菜单后仍可以生效。

为了防止同一菜单下两个功能发生冲突（例如在同一位置同时显示二值和灰度图像），你可以在初始化时设置是否在开启功能的同时关闭同菜单下的其他功能。

>   二级菜单 - 监视器

![IMG_20210824_165033](https://raw.githubusercontent.com/FerostMask/Photos_repository/master/IMG_20210824_021746.jpg)

监视器菜单用于实时显示一些变量，这项功能在检查各类元器件是否正常工作时起到非常大的作用。

通过对定时器和参数的设置，就能够实现该菜单的功能。

## 项目文件结构说明

本项目主要文件位于Project文件夹下的CODE文件夹内

-   CODE

    -   menu：一级菜单相关的代码和参数

    -   menu_2init：用于存放二级菜单的初始化函数
    -   menu_2：二级菜单页面布局和功能实现
    -   para_flash：二级菜单下参数存储功能实现
    -   data：存放整个项目范围会用到的全局变量
    
-   Libraries
    -   fontlib：存放菜单中文部分用到的编码
