from kivymd.app import MDApp
from kivymd.uix.screen import MDScreen

class MyWidget(MDScreen):
    pass

class BasicApp(MDApp):
    def build(self):
        self.theme_cls.primary_palette = "Blue"
        self.theme_cls.primary_hue = '200'
        self.theme_cls.accent_palette = "Blue"
        return MyWidget()


BasicApp().run()