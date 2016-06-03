# - Try to find Jsoncpp
# Once done, this will define
#
#  Jsoncpp_FOUND - system has Jsoncpp
#  Jsoncpp_INCLUDE_DIRS - the Jsoncpp include directories
#  Jsoncpp_LIBRARY_DIRS - link these to use Jsoncpp

include(LibFindMacros)

# Use pkg-config to get hints about paths
libfind_pkg_check_modules(Jsoncpp_PKGCONF jsoncpp)

# Include dir
find_path(Jsoncpp_INCLUDE_DIRS
	NAMES json/features.h
	PATH_SUFFIXES jsoncpp
	PATHS ${Jsoncpp_PKGCONF_INCLUDE_DIRS} 
)

# Finally the library itself
find_library(Jsoncpp_LIBRARY_DIRS
	NAMES jsoncpp
	PATHS ${Jsoncpp_PKGCONF_LIBRARY_DIRS}
)

