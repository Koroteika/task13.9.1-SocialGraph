# task13.9.1 / Social Graph
## **Классы**
### Graph
Этот класс реализует граф с матрицей смежности (двумерный массив matrix[SIZE][SIZE]).
### Методы
void addEdge(int v1, int v2) - добавляет ребра (связи) между v1 и v2.
void delEdge(int v1, int v2) - удаляет связь.
bool connected(int v1, int v2) - проверяет есть ли связь между ребрами.
void findMostTree(int start, bool res[SIZE]) - BFS-поиск, находит всех людей, находящихся на расстоянии ≤ 3 рукопожатий.
### Human
Этот класс управляет списком людей, а также дружбой между людьми.
### Методы
void addHuman(const std::string& name) - добавляет человека.
void addFriendship(const std::string& name1, const std::string& name2) - создает дружескую связь между людьми.
void delFriendship(const std::string& name1, const std::string& name2) - удаляет дружескую связь между людьми.
bool areFriends(const std::string& name1, const std::string& name2) - проверяет, являются ли люди друзьями.
void findMostTreeH() - находит все пары людей, которые знакомы через ≤ 3 рукопожатия.
int findIndex(const std::string& name) - ищет индекс человека в массиве.
