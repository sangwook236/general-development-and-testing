## Usage Guide

##### General
- Site
	- [MinGW32](http://www.mingw.org/)
		- http://sourceforge.net/projects/mingw/files/MinGW/Base/
		- http://sourceforge.net/projects/mingw/files/MinGW/Extension/
			- mingw-utils
			- peexports
			- reimp
		- http://sourceforge.net/projects/mingw/files/MinGW/Contributed/
	
		- http://sourceforge.net/projects/mingw/files/MSYS/Base/
		- http://sourceforge.net/projects/mingw/files/MSYS/Extension/
			- wget
		- http://sourceforge.net/projects/mingw/files/MSYS/Contributed/
	- [MinGW64](http://mingw-w64.org/)

- Document
	- http://www.mingw.org/wiki
	- http://www.mingw.org/wiki/HOWTO
	- http://www.mingw.org/wiki/FAQ

	- http://www.mingw.org/wiki/MSVC_and_MinGW_DLLs
	- http://www.mingw.org/wiki/Interoperability_of_Libraries_Created_by_Different_Compiler_Brands
	- http://www.mingw.org/wiki/JNI_MinGW_DLL

- Usage
	- Reference
  	- ${GDT_HOME}/sw_dev/cpp/rnd/src/probabilistic_graphical_model/mocapy/mocapy_build_guide.txt

##### Console
- Use Windows Command Prompt or Visual Studio Command Prompt
	- MSYS console를 사용하는 것보다 유리.
	- 사용하기 전에 ${MINGW_ROOT}/bin & ${MSYS_ROOT}/bin을 path의 첫 항목으로 설정하여야 함.
		- `set path=${MINGW_ROOT}/bin;%path%`
		- `set path=${MINGW_ROOT}/bin;${MSYS_ROOT}/bin;%path%`
		- `set path=${MINGW_ROOT}/bin;${CYGWIN_HOME}/bin;%path%`
		- `set path=${MINGW_ROOT}/bin;${GNUWIN32_HOME}/bin;%path%`
- Use MSYS console
	- 사용하기 전에 ${MINGW_ROOT}/bin을 path의 첫 항목으로 설정하여야 함.
		- `export PATH=${MINGW_ROOT}/bin:$PATH`
			- e.g.) `export PATH=/d/MyProgramFiles2/MinGW/bin:$PATH`

##### Package Management
- 아래의 executable file을 이용해서 package management를 수행
	- `${MINGW_ROOT}/bin/mingw-get.exe`
	- e.g.)
		- `mingw-get install lib-package-name`
		- `mingw-get update`

- mingw-get.exe으로 설치되지 않는 package의 경우 아래의 사이트에서 찾을 수 있음
	- http://sourceforge.net/projects/mingw/files/MSYS/Extension/
	- http://sourceforge.net/projects/mingw/files/MSYS/Base/
	- download 받은 file을 ${MSYS_HOME}에 복사한 후 압축을 풀면 `${MSYS_HOME}/bin`에 복사됨.

## Software Building

##### Software building을 위해서 사용할 compiler & linker, etc
- ${MINGW_ROOT}/bin 하위의 file을 사용
- "mingw32-"이 없는 executable file을 사용
	- e.g.)
		- mingw32-gcc.exe (X) ==> gcc.exe (O)
		- mingw32-g++.exe (X) ==> g++.exe (O)
	- 단, make의 경우 mingw32-make.exe를 사용
		- make.exe (X) ==> mingw32-make.exe (O)

##### Use CMake
- In Visual Studio Command Prompt or Windows Command Prompt
	- [ref] http://icl.cs.utk.edu/lapack-for-windows/lapack/
	1. set the GNU runtime directory in PATH.
		- `set path=${MINGW_ROOT}/bin;%path%`
		- `set path=${MINGW_ROOT}/bin;${CYGWIN_HOME}/bin;%path%`
	2. run cmake-gui.
	3. specify 'MinGW Makefiles' as the generator.
		-  sh.exe 관련 오류가 발생하면 'Configure' 재실행.
			- <error message> sh.exe was found in your PATH
			- 4번 참고.
		- Fortran compiler 관련 오류가 발생하면
			- <error message> The Fortran compiler `C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/bin/ifc.exe` is not able to compile a simple test program.
			- 4번 참고.
	4. set options.
		- set the 'CMAKE_SH' option to `${MSYS_ROOT}/bin/sh.exe`
		- set the 'CMAKE_Fortran_COMPILER' option to `${MINGW_ROOT}/bin/gfortran.exe`
		- set the 'BUILD_SHARED_LIBS' option to ON.
			- 이 option을 지정하지 않으면 .a library file 생성.
		- set the 'CMAKE_GNUtoMS' option to ON.
			- [ref] https://cmake.org/cmake/help/v3.0/prop_tgt/GNUtoMS.html
			- <warning message> Disabling CMAKE_GNUtoMS option because CMAKE_GNUtoMS_VCVARS is not set
			- set the 'CMAKE_GNUtoMS_VCVARS' option to `C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/bin/vcvars32.bat`
	5. configure and generate.
	6. cd cmake-build directory.
	7. run make.
		- `mingw32-make`
		- `mingw32-make PREFIX=${INSTAL_PREFIX} install`
- In MSYS console (==> not working)
	1. set ${MINGW_ROOT}/bin path.
		- `export PATH=${MINGW_ROOT}/bin:$PATH`
	2. run cmake-gui.
		- Windows용 software 사용 가능.
	3. specify 'MSYS Makefiles' as the generator.

##### Installation Prefix Setting
- MinGW나 MSYS의 경우 `/usr` 이나 `/usr/local directory`가 없음
	- 따라서, software installation prefix로 아래의 directory를 사용하여야 함.
		- `--prefix=${MINGW_ROOT}` or `--prefix=${INSTALLED_DIR}`
	- 그러면 아래의 directory에 installation file이 추가.
		- `${MINGW_ROOT}/include` or `${MSYS_ROOT}/include`
		- `${MINGW_ROOT}/lib` or `${MSYS_ROOT}/lib`