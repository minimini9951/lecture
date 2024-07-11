
#ifndef AE_EXPORT_H
#define AE_EXPORT_H

#ifndef EPSILON
	#define	EPSILON	0.00001f
#endif

#ifndef PI
	#define	PI		3.1415926f
#endif

#define	HALF_PI	(PI * 0.5f)
#define	TWO_PI	(PI * 2.0f)


#ifdef AE_FINAL
	#define PRINT(...)
#else
	#define PRINT(...)	printf(__VA_ARGS__)
#endif

#ifdef AE_FINAL
	#define PRINT_INFO(...)
#else
	#define PRINT_INFO(...)	PRINT("File: %s\nLine: %d\nFunc: %s\n\n",				\
										__FILE__,__LINE__, __FUNCTION__);	
#endif


//#ifdef AE_EXPORTS
	#define AE_API __declspec(dllexport)
//#else
//	#define AE_API __declspec(dllimport)
	//#define AE_API
//#endif				
	
#endif		// File