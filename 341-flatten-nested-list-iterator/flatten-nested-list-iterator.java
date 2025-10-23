/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return empty list if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class NestedIterator implements Iterator<Integer> {
    private ArrayList<Integer>arr;
    private int n,i;

    public NestedIterator(List<NestedInteger> list) {    
        arr = new ArrayList<>();

        for(var iter: list){
            helper(iter);
        }

        n=arr.size();
        i=0;
    }

    private void helper(NestedInteger curr){

        if(curr.isInteger()){
            arr.add(curr.getInteger());
        }
        
        else{
            for(var iter : curr.getList()){
                helper(iter);
            }
        }

        return;
    }


    

    @Override
    public Integer next() {
        int curr = arr.get(i);
        i++;
        return curr;
    }

    @Override
    public boolean hasNext() {
        return i<n;
    }
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */