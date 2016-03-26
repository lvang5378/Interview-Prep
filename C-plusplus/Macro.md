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
---

##3 Macros
https://gcc.gnu.org/onlinedocs/cpp/Macros.html
- Object-like Macros

```c++
   #define BUFFER_SIZE 1024
```
- Function-like Macros

```c++
#define foreach(list, index) for(index = 0; index < list.size(); index++)
//as to 
foreach(cookies, i)
    printf("Cookie: %s", cookies[i]);
//bad example: foreach not recommend in macro use, use BOOST_FOREACH　instead
/*
I disagree, chrish. Before lambda's, for_each was a nasty thing, because the code each element was runnnig 
through was not local to the calling point. foreach, (and I highly recommend BOOST_FOREACH instead of a 
hand-rolled solution) let's you keep the code close to the iteration site, making it more readable. 
That said, once lambda's roll out, for_each might once again be the way to go
*/
```
