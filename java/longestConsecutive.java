import java.util.HashSet;
import java.util.Set;


public class longestConsecutive {

    public static int findLongestSequence(int[] nums) {

        Set<Integer> set = new HashSet<>();
        
        for (int x : nums) {
            set.add(x);
        }

        int maxCount = Integer.MIN_VALUE;

        for (int num : nums) {

            int count = 0;

            if (!set.contains(num - 1)) {

                while (set.contains(num++)) {
                    count++;
                    maxCount = Math.max(count, maxCount);
                }

            }
        }

        return maxCount;
    }
    public static void main(String[] args) {
        int arr[] = {100, 4, 200, 1, 3, 2};
       
        //int arr[] = { 0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
        int ans = findLongestSequence(arr);
        System.out.println(ans);
    }
}