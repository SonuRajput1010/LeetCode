class RandomizedSet {

    private List<Integer> list;
    private Map<Integer, Integer> map;
    private Random rand;

    public RandomizedSet() {
        list = new ArrayList<>();
        map = new HashMap<>();
        rand = new Random();
    }

    public boolean insert(int val) {
        if (map.containsKey(val)) return false;

        map.put(val, list.size());
        list.add(val);

        return true;
    }

    public boolean remove(int val) {
        if (!map.containsKey(val)) return false;

        int index = map.get(val);
        int lastValue = list.get(list.size() - 1);

        list.set(index, lastValue);
        map.put(lastValue, index);

        list.remove(list.size() - 1);
        map.remove(val);

        return true;
    }

    public int getRandom() {
        int idx = rand.nextInt(list.size());
        return list.get(idx);
    }
}
