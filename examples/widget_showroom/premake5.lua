project "widget_showroom"
	kind "ConsoleApp"
	defines {"_CONSOLE", "HORUS_IMPORTS"}
	includedirs {scriptRoot, scriptRoot.."/include"}
  includedirs {scriptRoot.."/examples/common"}
	add_sources_from("./")
	files { "../common/sdl2*.h" }
	files { "../common/sdl2*.cpp" }
	files { "../common/opengl*.h" }
	files { "../common/opengl*.cpp" }

	link_horus()
	link_binpack()
	link_win32()
	link_opengl()
	link_glew()
	link_freetype()
	link_jsoncpp()
	link_stb_image()
	link_nfd()
	link_sdl2()
	
	filter {"system:linux"}
    linkgroups "On"
		buildoptions {"`pkg-config --cflags gtk+-3.0` -fPIC"}
		links {"X11 `pkg-config --libs gtk+-3.0`"}
		links {"Xi", "dl"}
	filter {}
	
	filter {"system:macosx"}
		links {"OpenGL.framework", "ForceFeedback.framework", "CoreVideo.framework", "Cocoa.framework", "IOKit.framework", "Carbon.framework", "CoreAudio.framework", "AudioToolbox.framework", "dl"}
	filter {}
	
	configuration "Debug"
		defines {}
		symbols "On"
		targetname "widget_showroom_d"
	
	configuration "Release"
		defines
		{
			"NDEBUG"
		}
		optimize "On"
		targetname "widget_showroom"