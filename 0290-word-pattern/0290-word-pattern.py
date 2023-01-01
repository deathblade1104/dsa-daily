class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
            # Split s into a list of strings
        s_list = s.split()

        # Check if the length of pattern and s_list are equal
        if len(pattern) != len(s_list):
            return False

        # Create empty dictionaries for mapping characters in pattern to strings in s_list,
        # and for storing the strings that have already been mapped
        char_to_string = {}
        used_strings = set()

        # Iterate through pattern and s_list
        for i in range(len(pattern)):
            # If the current character in pattern has not been mapped to a string yet
            if pattern[i] not in char_to_string:
                # Check if the current string in s_list has already been mapped to a character
                if s_list[i] in used_strings:
                    return False
                # If not, map the current character in pattern to the current string in s_list
                char_to_string[pattern[i]] = s_list[i]
                # Add the current string in s_list to the set of used strings
                used_strings.add(s_list[i])
            # If the current character in pattern has already been mapped to a string
            else:
                # Check if the current string in s_list is not the same as the previously mapped string
                if s_list[i] != char_to_string[pattern[i]]:
                    return False

        # If all elements in pattern and s_list match, return True
        return True
        