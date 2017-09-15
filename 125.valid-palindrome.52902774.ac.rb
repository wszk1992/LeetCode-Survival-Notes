# @param {String} s
# @return {Boolean}
def is_palindrome(string)
    return string.gsub(/[^0-9A-Za-z]/,'').downcase==string.gsub(/[^0-9A-Za-z]/,'').downcase.reverse
end