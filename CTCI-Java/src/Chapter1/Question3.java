package Chapter1;

/**
 * Created by cptmidler on 7/6/17.
 */
public class Question3 {

    private void shiftArray(char[] arr, int index){
        for(int i = index+3; i<arr.length; i++)
            arr[i] = arr[i-3];
        arr[index] = '%';
        arr[index+1] = '2';
        arr[index+2] = '0';
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
