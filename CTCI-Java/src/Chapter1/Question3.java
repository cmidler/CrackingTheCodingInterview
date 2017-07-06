package Chapter1;

/**
 * Created by cptmidler on 7/6/17.
 */
public class Question3 {

    private void shiftArray(char[] arr, int index){
        System.out.println(index);
        arr[index] = '%';
        char tmp1 = '2';
        char tmp2 = '0';
        int i = index;
        for(; i<arr.length-1; i+=2) {

            char tmp = arr[i];
            arr[i] = tmp1;
            tmp1 = tmp;
            tmp = arr[i+1];
            arr[i+1] = tmp2;
            tmp2 = tmp;
        }

        if(i<arr.length)
            arr[i] = tmp1;


    }

    public void urlify(char[] arr)
    {
        for(int i = 0; i< arr.length; i++)
            if(arr[i] == ' ')
            {
                System.out.println(arr);
                shiftArray(arr, i);
                System.out.println(arr);
                i+=2;
            }
    }

    public static void main(String[] args) {
        char[] arr1 = "Testing".toCharArray();
        char[] arr2 = "This is a test      ".toCharArray();
        Question3 q3 = new Question3();
        q3.urlify(arr1);
        q3.urlify(arr2);
        System.out.println(arr1);
        System.out.println(arr2);
    }
}
