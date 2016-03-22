import java.util.ArrayList;

/* use instanceof operator to check object type instead of Enum 
 * tutorial of instanceof: https://docs.oracle.com/javase/tutorial/java/nutsandbolts/op2.html
 */
public class Container2 {
    ArrayList<Element> data_list = new ArrayList<Element>();

    public Container2(){
        return;
    }

    int sum(){
        // type casting in inheritance: http://stackoverflow.com/a/20097325
        int sum = 0;
        for (Element element : data_list) {
            if (element instanceof ElementInt) {
                ElementInt element1 = (ElementInt) element;
                sum += element1.data;
            }
            else if (element instanceof ElementDouble) {
                ElementDouble element1 = (ElementDouble) element;
                sum += element1.data;
            }
            else if (element instanceof ElementString) {
                ElementString element1 = (ElementString) element;
                sum += element1.data.length();
            }
        }
        return sum;
    }

    /* testing code of module Container */
    static public void main(String args[]){
        Container2 c1 = new Container2();
        ElementInt e1 = new ElementInt(2);
        ElementDouble e2 = new ElementDouble(4.0);
        ElementString e3 = new ElementString("hello world");

        c1.data_list.add(e1);
        c1.data_list.add(e2);
        c1.data_list.add(e3);

        System.out.println(c1.sum());
        return;
    }
}

class Element {
}

class ElementInt extends Element {
    int data;
    ElementInt(int data){
        this.data = data;
    }
}

class ElementDouble extends Element {
    double data;
    ElementDouble(double data){
        this.data = data;
    }
}

class ElementString extends Element{
    String data;
    ElementString(String data){
        this.data = data;
    }
}
