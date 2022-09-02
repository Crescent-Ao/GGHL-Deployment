# GGHL-Deployment
初步计划实现对以下平台的推理，分别是
- NCNN(完成）
- openvino（无AVX512）
- tensorrt（实现）
- onnxruntime(python API)
## TensorRT
- FP-16 load image 16.32ms
- FP-16 nms 48.32ms
- FP-16 inference 5ms
## NCNN
- PNNX(转换已完成)
- 推理已完成
- 解码完成
