# 目录

- [项目说明](#项目说明)
  - [简单介绍](#简单介绍)
  - [开发环境](#开发环境)
- [玩法说明](#玩法说明)  
  - [概述](#概述)
  - [地图](#地图)
- [兼容性](#兼容性)
- [AI使用声明](#AI使用声明)
# 项目说明

## 简单介绍

本项目是一款以“连接”为主题的命令行游戏Pipe_Game，以水管的连接为主要内容，基于深度优先算法（DFS）。
## 开发环境
本项目全部用C++语言编写，使用Visual Studio 2019 IDE。
# 玩法说明
## 概述
在本游戏中，玩家将扮演一个出题人，创建一个以左上角和右下角分别为起点和终点的地图（长、宽均不大于50个字符）使游戏中的程序能够找到一条从起点到终点的一条水管通路。
## 地图
地图由“地图尺寸输入”和“地图数据”组成。

## 具体情境

一块矩形土地被分成n*m的单位正方形，现在这块土地已经埋设了一些水管。

水管将从矩形土地的左上角左部边缘，延伸到右下角右部边缘。

水管只有两种：弯管和直管

弯管有四种状态，直管有两种状态

0表示树木；1，2，3，4表示弯管四种状态；5，6表示直管两种状态。

## 输入

### 示例输入

示例输入如下：

```C++
5 4
5 3 5 3
1 5 3 0
2 3 5 1
6 1 1 5
1 5 5 4
```

### 地图尺寸输入
在第一行，玩家需要输入两个正整数m、n，以空格分隔，写完后回车切换到下一行输入。
其中，第一个数m代表地图的长（即纵向延伸的字符数量），第二个数n表示地图的宽（即横向延伸的字符数量）。如：

```C++
5 4
```

表示长为5，宽为4的地图。

### 地图数据

基于第一行输入的地图尺寸，玩家需要从第二行开始输入m行数据，每行包括n个正整数（每个正整数必须在1~6之间），同样以空格分隔每一个字符，用回车切换到下一行输入。

<img src="https://github.com/xxncx/Pipe_Game/blob/main/resources/image.png" alt="image" style="zoom:30%;" />

[示例输入](#示例输入)即可用于表示上图所示的地图

# 兼容性
本项目在以下配置的电脑下可以正常运行：
型号：Lenovo ThinkPad E431
系统信息：Windows 10 企业版 LTSC 21H2
处理器：Intel(R) Core(TM) i5-3320M CPU @ 2.60GHz
内存：8GB DDR3
显卡1：NVIDIA GeForce GT 740M
显卡2：Intel(R) HD Graphics 4000
声卡：Conexant 20671 SmartAudio HD

# AI使用声明
本项目在开发过程中使用了AI。
AI在本项目中主要用于：
1、标准化源程序
2、为程序编写详尽的注释
3、实现Python语言到C++语言的改写
4、对源代码进行解释以便于开发