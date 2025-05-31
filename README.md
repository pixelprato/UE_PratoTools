# Pixel-Prato Unreal Editor Tools

## Table of Contents

- [Tools](#tools)
- [Install](#install)
- [Version](#version)
- [Details](#details)

# Tools
The only tool for the moment is
- a __Teleport__:
  - You select an actors place your cursor elsewhere and press Shift+T to teleport!
  - <img src="images/teleport.gif" alt="" width="50%">

I had to extend Python with a little C++ function to get the mouse position in world from the viewport/camera. All the rest of the logic is done in Blueprint(Toolbox class).

# Version

This toolset contains a small Python librairy built with Unreal Editor __5.5.4__.
Source is there anaway, build it with your preferable version or ask if you want other version built, I can help.

# Install

Download and unzip.
</br><img src="images/Screenshot_7.jpg" alt="" width="50%">

Copy paste __*Content*__ & __*Plugins*__ folders in your Unreal Project.</br>
Re-open your project and verify that you have ToolBox of Unreal checked and my PratoPyLib in __*Edit / Plugins*__.

<img src="images/Screenshot_1.jpg" alt="ToolBox" width="50%">

<img src="images/Screenshot_2.jpg" alt="PraotPyLib" width="50%">

# Details

This blueprint is a Toolbox class. New tool feature arrived recently around 5.2 UE. Beaware that changing blueprint sometimes can crash Unreal, save twice like. 

You can browse the "toolbox" tab element under Content/Tools/PratoTools/UTB_Tab_1.
</br><img src="images/Screenshot_4.jpg" alt="" width="50%">

There's only one tab with one tool UBT_Teleport(1,2).
The powerful feature I found from this Unreal Toolbox is that __you can assign shortcuts__ without the need of coding C++ (3).
</br><img src="images/Screenshot_6.jpg" alt="" width="50%">

You can enable the display of the tab from __drawer__ or __viewport-frame(Viewport Overlay)__
</br><img src="images/Screenshot_3.jpg" alt="" width="50%">
</br>__warning__:If you uncheck the viewport one, no more shortcut will work, sadly.


