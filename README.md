#CCB-X-Reader for Cocos2d-X
This C++ class helps processing **ccb** files for your Cocos2d-X project. It's ported from the original CCBReader class of the popular **CocosBuilder** project.

Basically, CCB-X-Reader reads and parses the **ccb** files and creates and initilizes correspoding Cocos2d instances for your Cocos2d-X project. It's just like its CCBReader.m counterpart in a Cocos2d-iPhone project.

#How To Use
1. Add these two classes to your Cocos2d-X project.

		CCBReader.h
		CCBClassGenerator.h
	
2. Make sure all the .ccb/.png/.jpg etc files are properly copied and added into your Cocos2d-X project.
3. Try parse a .ccb file with one line of code.

		//Here we initialize a customized CCScene instance from *example.ccb* created from CocosBuilder
		CCScene *pScene = CCBReader::sceneWithNodeGraphFromFile("example.ccb");
4. C++ is not as dynamically implemented as Objective-C. For example, C++ is unable to create a class solely based on the class name string at runtime. Therefore we need a customized **CCBClassGenerator** class to handle all the Objective-C style dynamic stuff for us. The logic behind **CCBClassGenerator** is very simple. Basically all it does is string lookup. Make sure you have properly implemented the **CCBClassGenerator** class before running.

YouTube Demo (running on an Android device): <http://www.youtube.com/watch?v=QgA0fkse-AA>

#Contact
Email: <diwufet@gmail.com>

Blog post: <http://diwublog.com/archives/262>

![Screenshot](http://pic.yupoo.com/diwup_v/BVXXyLqY/11Z8la.jpg)