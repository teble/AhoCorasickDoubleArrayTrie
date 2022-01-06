AhoCorasickDoubleArrayTrie
---

fast c++11 implementation of Aho Corasick algorithm based on Double Array Trie(support unicode match).

Due to the particularity of c++char, unicode cannot be fully supported, 
so the string type used in this implementation is std::u16string.

# Usage

```c++
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
```

output:
```
[13:24]=how are you
[26:28]=在？
[29:38]=你没事吧，你还好吗
[34:39]=你还好吗?
```

# Thanks

This project is inspired by [hankcs/AhoCorasickDoubleArrayTrie](https://github.com/hankcs/AhoCorasickDoubleArrayTrie/). Many thanks!