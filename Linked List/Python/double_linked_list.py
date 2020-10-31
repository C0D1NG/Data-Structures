import copy

class Node:
    # Constructor
    def __init__(self, value):
        self.__value = value
        self.next = None
        self.previous = None

    # Getter
    @property
    def value(self):
        return self.__value

    # Setter
    @value.setter
    def value(self, value):
        self.__value = value

    # to string
    def __str__(self):
        return str(self.value)

class DoubleLinkedList:
    # Construtor da lista
    def __init__(self, size = 0, initial_value = None):
        # First Element
        self.__first = None
        # Last Element
        self.__last = None
        # Tamanho da lista
        self.__size = 0
        if size != 0:
            self.__initialize_list(size, initial_value)
    
    # Getter
    @property
    def size(self):
        return self.__size

    def __initialize_list(self, size, initial_value):
        if size < 0:
            print('Erro')
            return

        for _ in range(size):
            self.insert_begin(copy.deepcopy(initial_value))

    # Is list empty
    def __list_empty(self):
        return self.__size == 0

    # Change an value
    def change_value(self, value, position):
        if position > self.__size or position < 0:
            raise IndexError("List position out of range.")

        # List already empty
        if self.__list_empty():
            print("Erro, lista ja esta vazia")
            return

        node = self.__first
        element = 0
        while element != position:
            node = node.next
            element += 1
        node.value = value

    # Insert a value in the begin O(1)
    def insert_begin(self, value):
        node = Node(value)
        
        # List is empty. The value is the last
        if self.__list_empty():
            self.__last = node
        else:
            self.__first.previous = node

        node.next = self.__first
        self.__first = node
        self.__size += 1

    # Insert a value in the end O(1)
    def insert_end(self, value):
        node = Node(value)

        # List is empty. The value is the first
        if self.__list_empty():
            self.__first = node
        else:
            self.__last.next = node

        node.previous = self.__last
        self.__last = node
        self.__size += 1
    
    # Insert a value in the position O(n)
    def insert_position(self, value, position):
        if position > self.__size or position < 0:
            raise IndexError("List position out of range.")

        temp = self.__first
        if position == 0:
            self.insert_begin(value)
        elif position == self.__size:
            self.insert_end(value)
        else:
            element = 0
            while element != position - 1:
                temp = temp.next
                element += 1

            node = Node(value)
            node.previous = temp
            node.next = temp.next
            temp.next.previous = node
            temp.next = node

        self.__size += 1

    # Delete a value in the begin O(1)
    def delete_begin(self):
        if self.__list_empty():
            raise Warning('List is empty.')

        temp = self.__first

        if self.__first.next == None:
            self.__last = None
        else:
            self.__first.next.previous = None
        
        self.__first = self.__first.next
        self.__size -= 1
        return temp

    # Delete a value in the end O(1)
    def delete_end(self):
        if self.__list_empty():
            raise Warning('List is empty.')

        temp = self.__last

        if self.__last.previous == None:
            self.__first = None
        else:
            self.__last.previous.next = None
        
        self.__last = self.__last.previous
        self.__size -= 1
        return temp
    
    # Delete a value O(n)
    def delete_value(self, value):
        if self.__list_empty():
            raise Warning('List is empty.')

        temp = self.__first

        while temp != value:
            if temp == None:
                raise IndexError("Value out of List.")
            temp = temp.next

        if temp == self.__first:
            self.__first = temp.next
        else:
            temp.previous.next = temp.next

        if temp == self.__last:
            self.__last = temp.previous
        else:
            temp.next.previous = temp.previous
        
        self.__size -= 1
        return temp
    
    # Get value in the position O(n)
    def return_element(self, position):
        if position > self.__size or position < 0:
            raise IndexError("List position out of range.")

        if self.__list_empty():
            raise Warning('List is empty.')

        node = self.__first
        element = 0
        while element != position:
            node = node.next
            element += 1

        return node.value

    # Print in insertion order
    def print_order(self):
        node = self.__first
        while node != None:
            print(node)
            node = node.next

    # Print in reverse order
    def print_reverse_order(self):
        node = self.__last
        while node != None:
            print(node)
            node = node.previous

if __name__ == "__main__":
    list = DoubleLinkedList(10, False)
    list.print_order()
    print('---------------------------')
    list.change_value('true', 3)
    list.delete_end()
    list.insert_begin([False, True, False])
    print(list.return_element(0))
    print('---------------------------')
    list.print_reverse_order()
    print('---------------------------')
    list.insert_position(30, -1)