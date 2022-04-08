try:
    import pafy
except:
    # 改天pafy修正完畢後，下面指令可以改為!pip install pafy
    # !pip install git+https://github.com/Cupcakus/pafy
    # !pip install youtube_dl
    import pafy

try:
    import cv2
except:
    # !pip install opencv-python
    import cv2

url = "https://www.youtube.com/watch?v=X0uaGjVUY_E&t=611s"
ty_video = pafy.new(url, basic=False, gdata=False)
best = ty_video.getbest(preftype="mp4")
video = cv2.VideoCapture(best.url)

if video is not None:
    fps = int(video.get(cv2.CAP_PROP_FPS))
    width = int(video.get(cv2.CAP_PROP_FRAME_WIDTH))
    height = int(video.get(cv2.CAP_PROP_FRAME_HEIGHT))
    print('Frame rate:', fps, 'Frame width:', width, 'Frame height:', height)

    frame_num = 0
    play_flag = 1
    total_frame = int(video.get(cv2.CAP_PROP_FRAME_COUNT))

    def set_frame_number(x):
        global frame_num, play_flag
        if play_flag == 0:
            frame_num = x
            video.set(cv2.CAP_PROP_POS_FRAMES, frame_num)
        return

    def play(x):
        global play_flag
        play_flag = x
        return

    cv2.namedWindow('youtube')
    cv2.createTrackbar('frame no.', 'youtube', 0,
                       total_frame-1, set_frame_number)
    cv2.createTrackbar('play', 'youtube', 0, 1, play)
    cv2.setTrackbarPos('play', 'youtube', play_flag)

    while True:

        cv2.setTrackbarPos('frame no.', 'youtube', frame_num)

        if play_flag:
            grabbed, frame = video.read()
            cv2.imshow('youtube', frame)
            frame_num += 1

        k = cv2.waitKey(1000//fps)
        if k == 27:
            break

    cv2.destroyAllWindows()
    video.release()

else:
    print('cannot open {}'.format(url))
