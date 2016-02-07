import java.util.ArrayList;

public class Container {
    static public void main(String args[]){
        Container c1 = new Container();
        ElementInt e1 = new ElementInt(2);
        ElementDouble e2 = new ElementDouble(4.0);
        ElementString e3 = new ElementString("hello world");

        c1.data_list.add(e1);
        c1.data_list.add(e2);
        c1.data_list.add(e3);

        System.out.println(c1.sum());
        return;
    }

    ArrayList<Element> data_list = new ArrayList<Element>();

    public Container(){
        return;
    }

    int sum(){
        // type casting in inheritance: http://stackoverflow.com/a/20097325
        int sum = 0;
        for (Element element : data_list) {
            if (element.type == ElementType.INT) {
                ElementInt element1 = (ElementInt) element;
                sum += element1.data;
            }
            else if (element.type == ElementType.DOUBLE) {
                ElementDouble element1 = (ElementDouble) element;
                sum += element1.data;
            }
            else if (element.type == ElementType.STRING) {
                ElementString element1 = (ElementString) element;
                sum += element1.data.length();
            }
        }
        return sum;
    }
}

enum ElementType {
    NONE, INT, DOUBLE, STRING
}

class Element {
    ElementType type;    
    public Element(ElementType type){
        this.type = type;
    }
}

class ElementInt extends Element {
    int data;
    ElementInt(int data){
        super(ElementType.INT);
        this.data = data;
    }
}

class ElementDouble extends Element {
    double data;
    ElementDouble(double data){
        super(ElementType.DOUBLE);
        this.data = data;
    }
}

class ElementString extends Element{
    String data;
    ElementString(String data){
        super(ElementType.STRING);
        this.data = data;
    }
}
