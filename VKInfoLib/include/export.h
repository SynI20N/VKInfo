#ifndef VKINFOLIB_EXPORT_H_
#define VKINFOLIB_EXPORT_H_

#ifdef WIN64
    #ifdef VKINFO_EXPORTS
        /**
         * @brief Macro to export symbols when building the DLL on Windows.
         */
        #define VKINFO_API __declspec(dllexport)
    #else
        /**
         * @brief Macro to import symbols when using the DLL on Windows.
         */
        #define VKINFO_API __declspec(dllimport)
    #endif
#else
    /**
     * @brief Empty macro for non-Windows platforms (no import/export needed).
     */
    #define VKINFO_API
#endif

#endif // VKINFOLIB_EXPORT_H_