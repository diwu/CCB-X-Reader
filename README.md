#CCB-X-Reader for Cocos2d-X
This C++ class helps processing **ccb** files for your Cocos2d-X project. It's ported from the original CCBReader class of the popular **CocosBuilder** project. Note: the newly introduced **.ccbi** format is currently not supported.

Basically, CCB-X-Reader reads and parses the **ccb** files and creates and initilizes correspoding Cocos2d instances for your Cocos2d-X project. It's just like its CCBReader.m counterpart in a Cocos2d-iPhone project.

Once again, as of now, CCB-X-Reader only supports parsing **ccb** files. The newer and smaller **ccbi** format is currently not supported.

#How to Play with the Example Project
1. The enclosing example project is a standard Cocos2d-X project based on Cocos2d-1.0.1-x-0.13.0 beta. It was written and tested on both iPhone and Android.
2. How to play with it: build and run.

# How to Export CCB Files Using CocosBuilder
1. If you are using CocosBuilder 1.0, there's one and only one export format, and it's **ccb**.
2. However, if you are using CocosBuilder 1.1 or an even newer future version, the only export format is **ccbi**. But don't worry, take a look at the project file, it's actually right what we need, the **ccb** file.

#How To Use CCB-X-Reader
1. Add these two classes to your Cocos2d-X project.

		CCBReader.h
		CCBClassGenerator.h
	
2. Make sure all the .ccb/.png/.jpg etc files are properly copied and added into your Cocos2d-X project.
3. Try parse a .ccb file with one line of code.

		//Here we initialize a customized CCScene instance from *example.ccb* created from CocosBuilder
		CCScene *pScene = CCBReader::sceneWithNodeGraphFromFile("example.ccb");
4. C++ is not as dynamically implemented as Objective-C. For example, C++ is unable to create a class solely based on the class name string at runtime. Therefore we need a customized **CCBClassGenerator** class to handle all the Objective-C style dynamic stuff for us. The logic behind **CCBClassGenerator** is very simple. Basically all it does is string lookup. Make sure you have properly implemented the **CCBClassGenerator** class before running.

YouTube Demo (running on an Android device): <http://www.youtube.com/watch?v=QgA0fkse-AA>

#Known Issues
1. Due to some underlying bug in the Cocos2d-X implementation, when running on an iPhone 4s device, the example code will make the screen flicker.
2. This project is not finished yet. If you take a close look at the implementation, you'll see things like this:

		if (extraProps) {
			// To be implemented soon...
    	}
As the comments indicate, those missing parts will be implemented soon. At the same time, **You are welcome to contribute.**

#Contact
Email: <diwufet@gmail.com>

Blog post: <http://diwublog.com/archives/262>

![Screenshot](http://pic.yupoo.com/diwup_v/BVXXyLqY/11Z8la.jpg)