class Solution {
    public List<Integer> generateRow(int row){
        long ans = 1;
        List<Integer> ansRow = new ArrayList<>();
        ansRow.add((int)ans);
        for(int col=1; col<row; col++){
            ans = ans *( row - col);
            ans = ans/col;
            ansRow.add((int)ans);
        }
        return ansRow;
    }
    public List<List<Integer>> generate(int numRows) {
       List<List<Integer>> result = new ArrayList<>();

       for(int col = 1; col<=numRows; col++){
        result.add(generateRow(col));
       } 
       return result;
    }  
}