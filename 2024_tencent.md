## 收获
1. python切片索引如果越界不会报错，而是自动到边界值
2. python没有switch 大量的if 可以用字典来进行索引优化
3. python 需要注意 数字是string还是int 在url里的数字默认是string需要自己手动转换成int
4. SQLAlchemy 存在一个懒加载机制 
- 当你从数据库中查询一个对象时，这个对象将自动附加到你用来执行查询的 Session。然后，当你关闭 Session 或将对象从 Session 中显式分离时，对象将变为分离状态。在分离状态下，你仍然可以访问对象的属性，但是如果你尝试访问的属性是延迟加载的（也就是说，这个属性并没有在最初的查询中加载，而是在你首次访问它时才从数据库中加载），那么 SQLAlchemy 将抛出 DetachedInstanceError
- 为了解决这个问题，需要在session关闭前，把属性提取出来，比如在dao层返回一个对象转换成的字典，比如  return opera_item.as_dict()
5. 数据库查到的count的数据类型是decimal，通常需要转成int
6. k8s集群内部的其它服务可以用 proxy_pass:127.0.0.1+端口号转发 集群外则域名
7. c++ 
# pragma pack(1) 是一个编译器指令，用于设置结构体成员的对齐方式。在这个例子中，#pragma pack(1) 指令将结构体成员的对齐方式设置为 1 字节对齐。
- 在没有使用 #pragma pack 指令的情况下，编译器通常会根据目标平台的默认对齐规则来对齐结构体成员。这些默认对齐规则可能会导致结构体占用更多的内存空间，因为编译器会在成员之间插入填充字节（padding bytes）以满足对齐要求。
8. 一些常量的判断尽量用枚举类保存方便管理
9. 导出文件时 服务器存放的文件要么用临时文件要么及时删除
10. python2 others_info = others_info.strip().split(",") 这里others_info是一个空字符串 会返回[u'']
- Python 2 中，这个列表中的元素会被表示为 u''（一个 Unicode 空字符串）。在 Python 3 中，它会被表示为 ''（一个普通的空字符串）。
11. gorm 列名默认为snake_case



