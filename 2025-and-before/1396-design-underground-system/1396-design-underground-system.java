class UndergroundSystem {

    public static class Pair<K, V> {
        public K first;
        public V second;

        public Pair(K first, V second) {
            this.first = first;
            this.second = second;
        }

        public K getFirst() {
            return this.first;
        }

        public V getSecond() {
            return this.second;
        }
    }

    HashMap<Integer, Pair<String, Integer>> checkInMp;
    HashMap<String, Pair<Integer, Integer>> timeMp;

    public UndergroundSystem() {
        checkInMp = new HashMap<>();
        timeMp = new HashMap<>();
    }

    public void checkIn(int id, String stationName, int t) {
        checkInMp.put(id, new Pair<>(stationName, t));
    }

    private String getKey(String s1, String s2) {
        return s1 + "_" + s2;
    }

    public void checkOut(int id, String stationName, int t) {
        if (checkInMp.containsKey(id)) {
            Pair<String, Integer> checkInDetails = checkInMp.get(id);
            String key = getKey(checkInDetails.first, stationName);

            Pair<Integer, Integer> def = timeMp.getOrDefault(key, new Pair<>(0, 0));
            def.first += t - checkInDetails.second;
            def.second++;
            timeMp.put(key, def);
        }
    }
    
    public double getAverageTime(String startStation, String endStation) {
        
         String key = getKey(startStation,endStation);
        Pair<Integer,Integer>def = timeMp.get(key);
        
        return (1.0 * def.first)/def.second;
        
        
        
    }
}

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem obj = new UndergroundSystem();
 * obj.checkIn(id,stationName,t);
 * obj.checkOut(id,stationName,t);
 * double param_3 = obj.getAverageTime(startStation,endStation);
 */