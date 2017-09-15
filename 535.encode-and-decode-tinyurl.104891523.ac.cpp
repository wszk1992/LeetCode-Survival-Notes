class Solution {
public:
    unordered_map<int, string> hash;
    int index = 1;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        hash[index] = longUrl;
        return "http://tinyurl.com/" + to_string(index++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int i = string("http://tinyurl.com/").size();
        return hash[stoi(shortUrl.substr(i))];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));