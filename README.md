BẮT ĐẦU

ĐỊNH NGHĨA Node
    data: SỐ NGUYÊN
    next: CON TRỎ ĐẾN Node
KẾT THÚC ĐỊNH NGHĨA

HÀM createNode(data: SỐ NGUYÊN) TRẢ VỀ CON TRỎ ĐẾN Node
    newNode = CẤP PHÁT BỘ NHỚ CHO Node
    newNode.data = data
    newNode.next = NULL
    TRẢ VỀ newNode
KẾT THÚC HÀM

HÀM insert(head: CON TRỎ ĐẾN Node, data: SỐ NGUYÊN) TRẢ VỀ CON TRỎ ĐẾN Node
    newNode = createNode(data)
    NẾU head BẰNG NULL THÌ
        head = newNode
        TRẢ VỀ head
    KẾT THÚC NẾU
    tmp = head
    KHI tmp.next KHÔNG BẰNG NULL THÌ
        tmp = tmp.next
    KẾT THÚC KHI
    tmp.next = newNode
    TRẢ VỀ head
KẾT THÚC HÀM

HÀM isPrime(n: SỐ NGUYÊN) TRẢ VỀ SỐ NGUYÊN
    NẾU n < 2 THÌ TRẢ VỀ 0
    CHO i TỪ 2 ĐẾN CĂN BẬC HAI CỦA n LÀM TĂNG DẦN
        NẾU n % i BẰNG 0 THÌ TRẢ VỀ 0
    KẾT THÚC CHO
    TRẢ VỀ 1
KẾT THÚC HÀM

HÀM printList(head: CON TRỎ ĐẾN Node)
    temp = head
    KHI temp KHÔNG BẰNG NULL THÌ
        IN temp.data
        temp = temp.next
    KẾT THÚC KHI
    IN "NULL"
KẾT THÚC HÀM

HÀM isPresent(head: CON TRỎ ĐẾN Node, data: SỐ NGUYÊN) TRẢ VỀ SỐ NGUYÊN
    temp = head
    KHI temp KHÔNG BẰNG NULL THÌ
        NẾU temp.data BẰNG data THÌ TRẢ VỀ 1
        temp = temp.next
    KẾT THÚC KHI
    TRẢ VỀ 0
KẾT THÚC HÀM

HÀM findBlumPairs(head: CON TRỎ ĐẾN Node, n: SỐ NGUYÊN)
    p1 = head
    count = 0
    KHI p1 KHÔNG BẰNG NULL THÌ
        p2 = p1.next
        KHI p2 KHÔNG BẰNG NULL THÌ
            sum = p1.data + p2.data
            NẾU sum < n VÀ isPresent(head, sum) BẰNG 1 THÌ
                IN "(" + p1.data + ", " + p2.data + ") "
                count = count + 1
            KẾT THÚC NẾU
            p2 = p2.next
        KẾT THÚC KHI
        p1 = p1.next
    KẾT THÚC KHI
    NẾU count BẰNG 0 THÌ
        IN "Không có cặp số hợp lệ"
    KẾT THÚC NẾU
    IN "\n"
KẾT THÚC HÀM

HÀM main()
    primeList = NULL
    productList = NULL
    n, m: SỐ NGUYÊN

    IN "Nhập giới hạn cho các số Blum (N): "
    ĐỌC n
    IN "Nhập số để kiểm tra (M): "
    ĐỌC m

    // Tạo danh sách các số Blum
    CHO i TỪ 2 ĐẾN n LÀM TĂNG DẦN
        NẾU isPrime(i) BẰNG 1 THÌ
            tmp = primeList
            KHI tmp KHÔNG BẰNG NULL THÌ
                product = tmp.data * i
                NẾU product >= n THÌ NGHỈ
                productList = insert(productList, product)
                tmp = tmp.next
            KẾT THÚC KHI
            square = i * i
            NẾU square < n THÌ
                productList = insert(productList, square)
            KẾT THÚC NẾU
            primeList = insert(primeList, i)
        KẾT THÚC NẾU
    KẾT THÚC CHO

    // In ra danh sách các số Blum
    IN "Các số Blum nhỏ hơn " + n + ":"
    printList(productList)

    // Yêu cầu 1
    IN "Các cặp số Blum có tổng cũng là số Blum:"
    findBlumPairs(productList, n)

    // Yêu cầu 2
    NẾU isPresent(productList, m) BẰNG 1 THÌ
        IN m + " là số Blum"
    KHÁC
        IN m + " không phải là số Blum"
    KẾT THÚC NẾU

KẾT THÚC HÀM

KẾT THÚC
