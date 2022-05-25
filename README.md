# Space_Hero
Sinh viên: Hoàng Huy Thắng (MSV: 21020130)

Bài tập lớn INT2215: SpaceHero

1/ Hướng dẫn cài đặt
- Yêu cầu : Máy có CodeBlock và đã download thư viện SDL2 trên https://www.libsdl.org/download-2.0.php.
- Download file zip code về tại github.
- Giải nén, sau đó add các file .cpp, .h vào project tạo được từ CodeBlock; các file .dll để vào thư mục mới Debug->bin; các file ảnh .bmp để vào thư mục mới img.
- Tại mục Build Options của project: Set up như hình dưới đây ![image](https://user-images.githubusercontent.com/100281796/170291267-2dc83747-9d4e-41b4-a157-e6f5a7e4cbb5.png)
![image](https://user-images.githubusercontent.com/100281796/170291411-92acec0a-d005-4859-a502-342b8fdd8f69.png)
![image](https://user-images.githubusercontent.com/100281796/170291505-7472aaac-8fcf-4428-9457-cf087d9dc009.png)

Lưu ý: tại phần Search directories các bạn tự trỏ đến đúng đường dẫn các thư mục include và lib trên thiết bị của mình.
- Build project (F9) để bắt đầu trò chơi.

2/ Mô tả

Thế giới đối mặt với thảm họa chưa từng có với hàng loạt thiên thạch lao đến. Dự đoán được điều này trước hàng chục năm, các nhà khoa học đã ra sức chế tạo ra một chiếc phi thuyền để giúp nhân loại thoát khỏi thảm kịch này. Nhiệm vụ của bạn là trở thành người hùng - vị cứu tinh của nhân loại điều khiển chiếc phi thuyền đó phá vỡ thiên thạch để trái đất bình yên.
- Hướng dẫn chơi: Sử dụng tổ hợp phím WASD hoặc 4 phím mũi tên để di chuyển phi thuyền, ấn phấm Space để bắn đạn.
- Nếu để viên thiên thạch chạm vào phi thuyền hoặc lao đến trái đất, bạn sẽ mất 1 mạng. Bạn có tổng cộng 3 mạng để cứu lấy trái đất.
- Điểm số được tính dựa vào thời gian bạn tồn tại.
![image](https://user-images.githubusercontent.com/100281796/170301412-dc42086a-a8cd-4460-8363-192cf0035ef1.png)

3/ Chức năng
- Di chuyển, bắn đạn
- Tính điểm

4/ Các kỹ thuật
- Sử dụng các hàm trong thư viện đồ họa SDL2
- Kỹ thuật lập trình cơ bản: mảng, lớp, random, con trỏ,...

5/ Kết luận
- Game tự code lại dựa trên kiến thức mình hiểu nên còn khá sơ khai và đơn giản.
- Điểm tâm đắc: học được cách set up thư viện ngoài và chia tách file làm dự án trung bình.
- Điểm chưa ưng ý: chưa giải quyết được các lỗi liên quan đến thư viện SDL2 mixer và ttf nên chưa tạo được âm thanh sinh động và nhiều chức năng khác cho game.![image](https://user-images.githubusercontent.com/100281796/170302413-5bc3b401-7a80-47a1-97e0-9fd069b1a763.png)
![image](https://user-images.githubusercontent.com/100281796/170302582-8c1b9c6a-b411-4cc4-a826-d9c3612c59e8.png)
- Hướng phát triển: nghiên cứu tìm ra nguyên nhân để giải quyết vấn đề trên để xây dựng thêm nhiều tính năng như: menu chọn độ khó, lưu lại điểm cao,... Ngoài ra tạo ra thêm nhiều đối tượng đạn bắn và thiên thạch cho game thêm sinh động. Tạo hiếu ứng thiên thạch to vỡ ra nhiều mảnh nhỏ để yêu cầu phá hủy (độ khó cao hơn).
- Tự đánh giá: 7-8 điểm.

