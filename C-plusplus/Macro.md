##Inside conditional compilation, to overcome issues of differences between compilers:
```c++
#ifdef ARE_WE_ON_WIN32
#define close(parm1)            _close (parm1)
#define rmdir(parm1)            _rmdir (parm1)
#define mkdir(parm1, parm2)     _mkdir (parm1)
#define access(parm1, parm2)    _access(parm1, parm2)
#define create(parm1, parm2)    _creat (parm1, parm2)
#define unlink(parm1)           _unlink(parm1)
#endif
```
