# 在 Windows 10 上，即使“立体声混音”（Stereo Mix）被禁用，你依然可以使用 Windows Audio Session API（WASAPI）的“Loopback Capture”（循环录制）功能来捕获系统输出的声音。这种方式直接从音频输出流中获取数据，无需依赖传统的“立体声混音”设备。

# 实现方式
# 使用 WASAPI Loopback Capture

# **C# 示例：**可以利用开源库 NAudio 中的 WasapiLoopbackCapture 类实现。例如：

        # using NAudio.CoreAudioApi;
        # using NAudio.Wave;

        # var capture = new WasapiLoopbackCapture();
        # capture.DataAvailable += (s, e) =>
        # {
        #     // 在此处理捕获到的音频数据（例如传递给语音识别模块）
        # };
        # capture.StartRecording();

                # **Python 示例：**部分库（如 sounddevice）支持 WASAPI 后端，可以配置使用 WASAPI 来捕获系统音频。
                # 原理说明
                # WASAPI 的 loopback 模式允许你获取当前播放在输出设备（如扬声器或耳机）上的音频数据。Wallpaper 等工具正是利用这一特性，在立体声混响（Stereo Mix）不可用时仍能捕获系统声音。

                # 其他方案

                # **虚拟音频线路（Virtual Audio Cable）：**这种方式会在系统中创建一个虚拟输入设备，将系统输出路由到虚拟设备后再采集，但配置相对复杂且增加额外软件依赖。
                # **调整驱动设置：**在某些情况下，你也可以尝试在音频设备的属性中取消“独占模式”或启用“立体混响”，但这不是通用方案。
                # 总结
                # 利用 WASAPI loopback 捕获是目前较为简洁且系统原生支持的方案，能帮助你在不依赖“立体声混音”的前提下实现实时捕获系统音频，并进一步转化为文字。



#你可以使用 Python 的 sounddevice 库来实现 WASAPI 的 loopback 捕获，这样就可以在不依赖“立体声混音”的情况下获取系统输出音频。下面是一个简单的示例代码，它会捕获系统音频并在回调中打印采样数据

import sounddevice as sd
import numpy as np

# 列出所有设备，便于查找支持 loopback 的输出设备
print(sd.query_devices())

# 请根据打印出的设备列表，选择一个支持 loopback 模式的输出设备名称
# 例如："Speakers (Realtek High Definition Audio) (loopback)"
device_name = "Speakers (Realtek High Definition Audio) (loopback)"
device_info = None
for dev in sd.query_devices():
    if device_name in dev['name']:
        device_info = dev
        break

if device_info is None:
    print("找不到指定的 loopback 设备")
    exit(1)

samplerate = int(device_info['default_samplerate'])
channels = device_info['max_input_channels']

def audio_callback(indata, frames, time, status):
    if status:
        print("Status:", status)
    # 这里 indata 为捕获到的音频数据，可以后续传给语音识别模块
    print("Captured data shape:", indata.shape)

# 开启输入流，设置 loopback=True 即可捕获系统输出音频
with sd.InputStream(samplerate=samplerate,
                    channels=channels,
                    callback=audio_callback,
                    device=device_info['name'],
                    loopback=True):
    print("正在捕获系统音频，按 Ctrl+C 停止...")
    while True:
        sd.sleep(1000)
# 说明
# 设备选择：通过 sd.query_devices() 可以获取系统中的所有音频设备。通常在 WASAPI 下，系统会将支持 loopback 的设备以 “(loopback)” 标记出来，选择合适的设备名称后传入 InputStream 的 device 参数即可。
# loopback 模式：设置 loopback=True 后，sounddevice 会从指定输出设备的音频流中捕获数据，而不是从麦克风等传统输入设备采集。
# 后续处理：在 audio_callback 中，你可以将捕获到的音频数据（通常是 NumPy 数组形式）传入语音识别引擎，实现音频转文字。
# 这种方法是基于 WASAPI 的原生支持，不需要修改驱动或依赖外部虚拟音频设备，是目前较为简洁高效的方案。