-- premake.lua
workspace "mpl_list"
   configurations { "Debug", "Release" }

project "mpl_list"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

   files { "./include/**.h", "./src/**.cpp", "./include/**.hh", "./include/**.hpp" }
   flags { "FatalWarnings", "C++14" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"