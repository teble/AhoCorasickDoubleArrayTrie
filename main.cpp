#include <bits/stdc++.h>
#include "ACDAT/Builder.h"

using namespace std;

std::string utf16_to_utf8(const std::u16string &utf16) {
    return std::wstring_convert<std::codecvt_utf8_utf16<char16_t, 0x10ffff,
            std::codecvt_mode::little_endian>, char16_t>().to_bytes(utf16);
}

std::u16string utf8_to_utf16(const std::string &utf8) {
    return std::wstring_convert<std::codecvt_utf8_utf16<char16_t, 0x10ffff,
            std::codecvt_mode::little_endian>, char16_t>().from_bytes(utf8);
}

int main() {
    vector<u16string> vector{
            u"你还好吗?",
            u"how are you",
            u"谢谢",
            u"在？",
            u"你没事吧，你还好吗"
    };
    map<u16string, string> map;
    for (auto &str: vector) {
        map[str] = utf16_to_utf8(str);
    }
    u16string text = u"test你好吗？你肿么了，how are you? 在？\n"
                     "你没事吧，你还好吗???";
    auto acdat = AhoCorasickDoubleArrayTrie<string>();
    Builder<string>().build(map, &acdat);
    std::function<void(int, int, string)> callback = [](int begin, int end, const string &value) -> void {
        printf("[%d:%d]=%s\n", begin, end, value.c_str());
    };
    acdat.parseText(text, callback);
    return 0;
}