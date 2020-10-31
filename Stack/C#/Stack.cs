public class Stack<T> {
  List<T> list = new List<>();
  int size;
  public Stack() {
    size = 0;
  }

  public void Push(T item){
    list.Add(0, item);
    size++;
  }
  public T Pop() {
    if(size > 0) {
      list.RemoveAt(0);
      size--;
    } 
  }

  public int Size() {
    return size;
  }
}
