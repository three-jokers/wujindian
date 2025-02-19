# wujindian
【任务描述】

设计一个五金店库存信息管理系统，对五金店的各类商品进行进销存管理。

【功能要求】

（1）产品管理：维护五金件信息表(包括：五金件编号、五金件名称、单价、库存)，
对五金产品信息进行登记和管理。管理包括：添加、删除、修改、查询、保存等。

（2）人员管理：维护销售人员信息表(包括：工号、姓名)，对五金店的销售人员信息
进行管理，包括：人员信息的添加、删除、修改、查询、保存等。

（3）销售信息管理：维护销售信息表(包括：五金件编号、五金件名称、购买数量、销
售日期、销售人员工号等)，管理五金件销售记录。实现：

退货管理：对已销售商品，进行退货处理，更新销售信息表。

进货提示：键盘输入当前月份，统计数量小于2的五金件，且该月销售10件以上，
则提示进货。

缺货统计：对已经卖完的五金件进行统计。

销量统计：键盘输入日期，统计该日各五金件的销售情况，并排序输出。

（4）员工销售业绩统计：统计每个员工的销售金额，并排序输出。
程序设计课程设计要求

1、本课程设计要求以小组为单位合作完成，每个小组最多3人。

2、每组成员(不得超过3人)合作完成一个课程设计题目，每个人的任务分工不同。课程设计报告中，要求说明每个成员的分工和贡献。

3、要求有菜单选择(switch)、文件读写(File)操作。涉及到的结构体等复合类型数据，可以使用数组，也可以使用链表保存。对于菜单的实现，可以用printf语句把程序的功能列出来，然后等待用户输入而执行不同的函数，执行完了一个功能后再回到菜单选择。

4、要求程序退出时，数据保存到文件；程序再次运行时，先从文件读入数据。可以用文本文件，也可以用二进制文件。推荐使用文本文件，以便程序调试和定位错误。

5、模块化程序设计：要求在设计的过程中，按功能定义函数或书写多个文件，进行模块化设计，各个功能模块用函数的形式来实现。

6、期末按照《课程设计报告-组长学号-姓名.docx》模板提交课程设计报告。



最终提交文件清单

1. 源代码(至少包括.c源代码文件)；
   
2. 程序运行所需的数据文件(如果有请和代码一起提供)；
   
3. 课程设计报告；（格式参考《课程设计报告-组长学号-姓名.docx》）

完成上述清单后，每组要求在课程设计课上完成课堂验收（组内所有成员均参加，每个成员都要求能读懂全部代码）。

验收完成后，将上述清单分别上传到网络教学平台的PBL作业中，每组传一份。

