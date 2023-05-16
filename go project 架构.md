## go project 架构
- service/handler
- logic/service
- const
- entity/model
- repo/dal
- config
- middleware
#### util存放工具函数，不应该依赖于任何其它层的代码
#### service层定义接口，应该只包含参数验证，日志打印，返回结果
#### 主要代码逻辑放在logic层，可以每个模块一个文件夹
