class Solution {
    public List<Integer> findSubstring(String s, String[] words) {

        List<Integer> ans = new ArrayList<>();

        int len = words[0].length();
        int totalWords = words.length;
        int totalLen = len * totalWords;

        if (s.length() < totalLen) return ans;

        Map<String, Integer> map = new HashMap<>();

        for (String string : words) {
            map.put(string, map.getOrDefault(string, 0) + 1);
        }

        for (int start = 0; start < len; start++) {

            int l = start;
            int count = 0;

            Map<String, Integer> copyMap = new HashMap<>();

            for (int r = start; r + len <= s.length(); r += len) {

                String str = s.substring(r, r + len);

                // Word doesn't exist
                if (!map.containsKey(str)) {
                    copyMap.clear();
                    count = 0;
                    l = r + len;
                    continue;
                }

                // Add current word
                copyMap.put(str, copyMap.getOrDefault(str, 0) + 1);
                count++;

                // Too many occurrences of this word
                while (copyMap.get(str) > map.get(str)) {

                    String leftStr = s.substring(l, l + len);

                    copyMap.put(leftStr, copyMap.get(leftStr) - 1);

                    l += len;
                    count--;
                }

                // Found all words
                if (count == totalWords) {

                    ans.add(l);

                    String leftStr = s.substring(l, l + len);

                    copyMap.put(leftStr, copyMap.get(leftStr) - 1);

                    l += len;
                    count--;
                }
            }
        }

        return ans;
    }
}