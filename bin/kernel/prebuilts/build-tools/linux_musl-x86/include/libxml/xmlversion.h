/**
 * @file
 *
 * @brief compile-time version information
 *
 * compile-time version information for the XML library
 *
 * @copyright See Copyright for the status of this software.
 *
 * @author Daniel Veillard
 */

#ifndef __XML_VERSION_H__
#define __XML_VERSION_H__

/**
 * the version string like "1.2.3"
 */
#define LIBXML_DOTTED_VERSION "2.16.0"

/**
 * the version number: 1.2.3 value is 10203
 */
#define LIBXML_VERSION 21600

/**
 * the version number string, 1.2.3 value is "10203"
 */
#define LIBXML_VERSION_STRING "21600"

/**
 * extra version information, used to show a git commit description
 */
#define LIBXML_VERSION_EXTRA "-GITv2.15.0-1352-g0c56291e3"

/**
 * Macro to check that the libxml version in use is compatible with
 * the version the software has been compiled against
 */
#define LIBXML_TEST_VERSION xmlCheckVersion(21600);

#if 1
/**
 * Whether the thread support is configured in
 */
#define LIBXML_THREAD_ENABLED
#endif

#if 0
/**
 * Whether the allocation hooks are per-thread
 */
#define LIBXML_THREAD_ALLOC_ENABLED
#endif

/**
 * Always enabled since 2.14.0
 */
#define LIBXML_TREE_ENABLED

#if 1
/**
 * Whether the serialization/saving support is configured in
 */
#define LIBXML_OUTPUT_ENABLED
#endif

#if 1
/**
 * Whether the push parsing interfaces are configured in
 */
#define LIBXML_PUSH_ENABLED
#endif

#if 1
/**
 * Whether the xmlReader parsing interface is configured in
 */
#define LIBXML_READER_ENABLED
#endif

#if 1
/**
 * Whether the xmlPattern node selection interface is configured in
 */
#define LIBXML_PATTERN_ENABLED
#endif

#if 1
/**
 * Whether the xmlWriter saving interface is configured in
 */
#define LIBXML_WRITER_ENABLED
#endif

#if 1
/**
 * Whether the older SAX1 interface is configured in
 */
#define LIBXML_SAX1_ENABLED
#endif

#if 0
/**
 * HTTP support was removed in 2.15
 */
#define LIBXML_HTTP_STUBS_ENABLED
#endif

#if 1
/**
 * Whether the DTD validation support is configured in
 */
#define LIBXML_VALID_ENABLED
#endif

#if 0
/**
 * Whether the HTML support is configured in
 */
#define LIBXML_HTML_ENABLED
#endif

/*
 * Removed in 2.14
 */
#undef LIBXML_LEGACY_ENABLED

#if 1
/**
 * Whether the Canonicalization support is configured in
 */
#define LIBXML_C14N_ENABLED
#endif

#if 1
/**
 * Whether the Catalog support is configured in
 */
#define LIBXML_CATALOG_ENABLED
#define LIBXML_SGML_CATALOG_ENABLED
#endif

#if 1
/**
 * Whether XPath is configured in
 */
#define LIBXML_XPATH_ENABLED
#endif

#if 1
/**
 * Whether XPointer is configured in
 */
#define LIBXML_XPTR_ENABLED
#endif

#if 1
/**
 * Whether XInclude is configured in
 */
#define LIBXML_XINCLUDE_ENABLED
#endif

#if 0
/**
 * Whether iconv support is available
 */
#define LIBXML_ICONV_ENABLED
#endif

/**
 * LIBXML_ICU_ENABLED:
 *
 * Whether icu support is available
 *
 * This is disabled when libxml2 is
 * 1. built for the VNDK.
 * libicuuc.so isn't available in the VNDK.
 * 2. built as an static library on Android
 * libicuuc.so isn't available for static linking.
 */
#undef LIBXML_ICU_ENABLED
#ifdef __ANDROID_VNDK__
#undef LIBXML_ICU_ENABLED
#elif defined(__ANDROID__) && defined(STATIC_LIBXML)
#undef LIBXML_ICU_ENABLED
#else
#define LIBXML_ICU_ENABLED
#endif

#if 1
/**
 * Whether ISO-8859-* support is made available in case iconv is not
 */
#define LIBXML_ISO8859X_ENABLED
#endif

#if 1
/**
 * Whether Debugging module is configured in
 */
#define LIBXML_DEBUG_ENABLED
#endif

/*
 * Removed in 2.14
 */
#undef LIBXML_UNICODE_ENABLED

#if 1
/**
 * Whether the regular expressions interfaces are compiled in
 */
#define LIBXML_REGEXP_ENABLED
#endif

#if 1
/**
 * Whether the automata interfaces are compiled in
 */
#define LIBXML_AUTOMATA_ENABLED
#endif

#if 1
/**
 * Whether the RelaxNG validation interfaces are compiled in
 */
#define LIBXML_RELAXNG_ENABLED
#endif

#if 1
/**
 * Whether the Schemas validation interfaces are compiled in
 */
#define LIBXML_SCHEMAS_ENABLED
#endif

#if 1
/**
 * Whether the Schematron validation interfaces are compiled in
 */
#define LIBXML_SCHEMATRON_ENABLED
#endif

#if 1
/**
 * Whether the module interfaces are compiled in
 */
#define LIBXML_MODULES_ENABLED
/**
 * the string suffix used by dynamic modules (usually shared libraries)
 */
#define LIBXML_MODULE_EXTENSION ".so" 
#endif

#if 0
/**
 * Whether the Zlib support is compiled in
 */
#define LIBXML_ZLIB_ENABLED
#endif

/**
 * LIBXML_LZMA_ENABLED:
 *
 * Whether the Lzma support is compiled in
 */
#if 0
#define LIBXML_LZMA_ENABLED
#endif

#ifdef __GNUC__
/** DOC_DISABLE */
#ifndef ATTRIBUTE_UNUSED
# if ((__GNUC__ > 2) || ((__GNUC__ == 2) && (__GNUC_MINOR__ >= 7)))
#  define ATTRIBUTE_UNUSED __attribute__((unused))
# else
#  define ATTRIBUTE_UNUSED
# endif
#endif

#ifndef LIBXML_ATTR_ALLOC_SIZE
# if (!defined(__clang__) && ((__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 3))))
#  define LIBXML_ATTR_ALLOC_SIZE(x) __attribute__((alloc_size(x)))
# else
#  define LIBXML_ATTR_ALLOC_SIZE(x)
# endif
#else
# define LIBXML_ATTR_ALLOC_SIZE(x)
#endif

#ifndef LIBXML_ATTR_FORMAT
# if ((__GNUC__ > 3) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 3)))
#  define LIBXML_ATTR_FORMAT(fmt,args) __attribute__((__format__(__printf__,fmt,args)))
# else
#  define LIBXML_ATTR_FORMAT(fmt,args)
# endif
#else
# define LIBXML_ATTR_FORMAT(fmt,args)
#endif

#ifndef XML_DEPRECATED
#  if defined (IN_LIBXML) || (__GNUC__ * 100 + __GNUC_MINOR__ < 301)
#    define XML_DEPRECATED
/* Available since at least GCC 3.1 */
#  else
#    define XML_DEPRECATED __attribute__((deprecated))
#  endif
#endif

#if defined(__clang__) || (__GNUC__ * 100 + __GNUC_MINOR__ >= 406)
#define XML_IGNORE_FPTR_CAST_WARNINGS \
    _Pragma("GCC diagnostic push") \
    _Pragma("GCC diagnostic ignored \"-Wpedantic\"") \
    _Pragma("GCC diagnostic ignored \"-Wcast-function-type\"")
#define XML_POP_WARNINGS \
    _Pragma("GCC diagnostic pop")
#else
  #define XML_IGNORE_FPTR_CAST_WARNINGS
  #define XML_POP_WARNINGS
#endif

#else /* ! __GNUC__ */
#define ATTRIBUTE_UNUSED
#define LIBXML_ATTR_ALLOC_SIZE(x)
#define LIBXML_ATTR_FORMAT(fmt,args)
#ifndef XML_DEPRECATED
#  if defined (IN_LIBXML) || !defined (_MSC_VER)
#    define XML_DEPRECATED
/* Available since Visual Studio 2005 */
#  elif defined (_MSC_VER) && (_MSC_VER >= 1400)
#    define XML_DEPRECATED __declspec(deprecated)
#  endif
#endif
#if defined (_MSC_VER) && (_MSC_VER >= 1400)
#  define XML_IGNORE_FPTR_CAST_WARNINGS __pragma(warning(push))
#else
#  define XML_IGNORE_FPTR_CAST_WARNINGS
#endif
#ifndef XML_POP_WARNINGS
#  if defined (_MSC_VER) && (_MSC_VER >= 1400)
#    define XML_POP_WARNINGS __pragma(warning(pop))
#  else
#    define XML_POP_WARNINGS
#  endif
#endif
#endif /* __GNUC__ */

#define XML_EMPTY

#ifdef LIBXML_THREAD_ENABLED
  #define XML_DECLARE_GLOBAL(name, type, attrs) \
    attrs XMLPUBFUN type *__##name(void);
  #define XML_GLOBAL_MACRO(name) (*__##name())
#else
  #define XML_DECLARE_GLOBAL(name, type, attrs) \
    attrs XMLPUBVAR type name;
#endif

#include <libxml/xmlexports.h>

#endif


