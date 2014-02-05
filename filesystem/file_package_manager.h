// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_FILESYSTEM_FILE_PACKAGE_MANAGER
#define INCLUDED_FILESYSTEM_FILE_PACKAGE_MANAGER

#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>

#include "ifile_package.h"

namespace frozenbyte {
    namespace filesystem {
        class IFileList;
        struct FilePackageManagerData;

        class FilePackageManager {
            boost::scoped_ptr<FilePackageManagerData> data;

        public:
            FilePackageManager();
            ~FilePackageManager();

            enum Mode {
                REQUIRED = 0, NOTREQUIRED = 1,
            };
            void addPackage(boost::shared_ptr<IFilePackage> filePackage, int priority);
            boost::shared_ptr<IFileList> findFiles(const std::string &dir,
                                                   const std::string &extension,
                                                   bool               caseSensitive = false);
            /** Open a file as an InputStream. If @p mode is not OPTIONAL an error will be logged. */
            InputStream getFile(const std::string &fileName, Mode mode = REQUIRED);
            unsigned int getCrc(const std::string &fileName);

            void setInputStreamErrorReporting(bool logNonExisting);

            static FilePackageManager&getInstance();
            static void setInstancePtr(FilePackageManager *instance);

        };

    } // end of namespace filesystem
}     // end of namespace frozenbyte

#endif
