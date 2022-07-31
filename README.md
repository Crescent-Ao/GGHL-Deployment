# GGHL-Deployment
初步计划实现对以下平台的推理，分别是
- NCNN(不带有解码头的权重存在一些问题)
- openvino
- tensorrt(INT8 未完成)
- onnxruntime(python API)
## TensorRT
- FP-16 load image 16.32ms
- FP-16 nms 48.32ms
- FP-16 inference 5ms
## NCNN
- PNNX(转换已完成)
- 推理已完成
- 解码完成
