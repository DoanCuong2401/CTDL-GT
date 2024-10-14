# Định nghĩa Node
Cấu trúc Node:
    - data: SỐ NGUYÊN
    - next: CON TRỎ ĐẾN Node

# Hàm tạo Node mới
Hàm createNode(data):
    new_node = CẤP PHÁT BỘ NHỚ CHO Node
    new_node.data = data
    new_node.next = NULL
    TRẢ VỀ new_node

# Hàm chèn Node mới vào danh sách
Hàm insert(head, data):
    new_node = createNode(data)
    NẾU head RỖNG:
        head = new_node
        TRẢ VỀ head
    current_node = head
    KHI current_node.next KHÔNG RỖNG:
        current_node = current_node.next
    current_node.next = new_node
    TRẢ VỀ head

# Hàm kiểm tra số nguyên tố
Hàm isPrime(n):
    NẾU n < 2:
        TRẢ VỀ false
    CHO i TỪ 2 ĐẾN CĂN BẬC HAI CỦA n:
        NẾU n CHIA HẾT cho i:
            TRẢ VỀ false
    TRẢ VỀ true

# Hàm in danh sách
Hàm printList(head):
    current_node = head
    KHI current_node KHÔNG RỖNG:
        in current_node.data
        current_node = current_node.next

# Hàm kiểm tra xem dữ liệu có tồn tại trong danh sách không
Hàm isPresent(head, data):
    current_node = head
    KHI current_node KHÔNG RỖNG:
        NẾU current_node.data BẰNG data:
            TRẢ VỀ true
        current_node = current_node.next
    TRẢ VỀ false

# Hàm tìm cặp số Blum
Hàm findBlumPairs(head, n):
    p1 = head
    count = 0
    KHI p1 KHÔNG RỖNG:
        p2 = p1.next
        KHI p2 KHÔNG RỖNG:
            sum = p1.data + p2.data
            NẾU sum < n VÀ isPresent(head, sum):
                in (p1.data, p2.data)
                count++
            p2 = p2.next
        p1 = p1.next
    NẾU count = 0:
        in "Không có cặp số hợp lệ"

# Hàm chính
Hàm main():
    prime_list = danh sách rỗng
    product_list = danh sách rỗng
    ĐỌC n và m từ người dùng

    // Tạo danh sách số Blum
    CHO i TỪ 2 ĐẾN n:
        NẾU isPrime(i):
            cho tmp trong prime_list:
                product = tmp.data * i
                NẾU product >= n:
                    NGHỈ
                insert product vào product_list
            square = i * i
            NẾU square < n:
                insert square vào product_list
            insert i vào prime_list

    // In ra danh sách số Blum
    in "Các số Blum nhỏ hơn n:"
    printList(product_list)

    // Tìm cặp số Blum có tổng cũng là số Blum
    in "Các cặp số Blum có tổng cũng là số Blum:"
    findBlumPairs(product_list, n)

    // Kiểm tra xem m có phải là số Blum không
    NẾU isPresent(product_list, m):
        in m, "là số Blum"
    KHÁC:
        in m, "không phải là số Blum"
