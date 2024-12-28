#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP

#include <string>
#include <algorithm>
#include <cctype>

// Inline normalizeString function
inline std::string normalizeString(const std::string& str) {
    std::string normalized = str;
    std::transform(normalized.begin(), normalized.end(), normalized.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return normalized;
}

#endif // STRING_UTILS_HPP
