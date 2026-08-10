class Solution {

    public boolean isConcatenated(String word, Set<String> set,Map<String, Boolean> memo) {

        if(memo.containsKey(word)) return memo.get(word);
        int n = word.length();

        for(int i = 0; i < n - 1; i++) {

            String prefix = word.substring(0, i + 1);
            String suffix = word.substring(i + 1);

             if (set.contains(prefix)) {

                if (set.contains(suffix) || isConcatenated(suffix, set, memo)) {
                    memo.put(word, true);
                    return true;
                }
            }
        }
        memo.put(word,false);
        return false;
    }

    public List<String> findAllConcatenatedWordsInADict(String[] words) {

        int n = words.length;

        Set<String> set = new HashSet<>();

        for(String ch : words) {
            set.add(ch);
        }

        List<String> result = new ArrayList<>();

        for (String word : words) {

            set.remove(word);

            Map<String, Boolean> memo = new HashMap<>();

            if (isConcatenated(word, set, memo)) {
                result.add(word);
            }


            set.add(word);
        }

        return result;
    }
}