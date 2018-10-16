
LiveUpdateps.dll: dlldata.obj LiveUpdate_p.obj LiveUpdate_i.obj
	link /dll /out:LiveUpdateps.dll /def:LiveUpdateps.def /entry:DllMain dlldata.obj LiveUpdate_p.obj LiveUpdate_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del LiveUpdateps.dll
	@del LiveUpdateps.lib
	@del LiveUpdateps.exp
	@del dlldata.obj
	@del LiveUpdate_p.obj
	@del LiveUpdate_i.obj
