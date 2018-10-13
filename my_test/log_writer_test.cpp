#include <iostream>
#include "db/log_writer.h"
#include "leveldb/env.h"
#include "util/crc32c.h"
#include "util/coding.h"

int main() {
    std::string file_name("log_writer.data");

    leveldb::WritableFile* file;
    leveldb::Status s = leveldb::Env::Default()->NewWritableFile(
            file_name,
            &file);

    leveldb::log::Writer writer(file);

    const std::string data = "this is a simple test";
    s = writer.AddRecord(data);//字符串长度21=0x15
    std::cout << s.ToString() << std::endl;

    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */